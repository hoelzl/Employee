// Created by Matthias Hölzl on 2019-05-28.
//

#include "Core/DefaultSalaryComputationStrategy.h"
#include "Core/FixedDateGenerator.h"
#include "Entities/Employee.h"
#include "Entities/Name.h"
#include "InputOutput/EmployeeFileReader.h"
#include "UseCases/AugmentedEmployeeListPrinter.h"
#include "UseCases/EmployeeListPrinter.h"
#include <iostream>

using ok::core::DefaultSalaryComputationStrategy;
using ok::core::FixedDateGenerator;
using ok::entities::Employee;
using ok::entities::Name;
using ok::input_output::EmployeeFileReader;
using ok::use_cases::AugmentedEmployeeListPrinter;
using ok::use_cases::EmployeeFactory;
using ok::use_cases::EmployeeListFactory;
using ok::use_cases::EmployeeListPrinter;

int main()
{
	std::unique_ptr<EmployeeListFactory> EmployeeListFactory{std::make_unique<EmployeeFileReader>(
		"employee-data.txt", std::make_shared<EmployeeFactory>())};
	std::unique_ptr<EmployeeListPrinter> ListPrinter{std::make_unique<AugmentedEmployeeListPrinter>(
		std::cout, std::make_shared<FixedDateGenerator>("2019-05-28"),
		std::make_shared<DefaultSalaryComputationStrategy>())};

	ListPrinter->PrintEmployeeList(EmployeeListFactory->CreateEmployees());
	return 0;
}
