#include "Console.h"
#include <iostream>
#include <crtdbg.h>

int main() {
	{
		std::shared_ptr<Person> person = std::make_shared<Person>("Adrian Popa");

		MedicalAnalysis* analysis1 = new BMI{ "2019.05.09", 23.4 };
		MedicalAnalysis* analysis2 = new BMI{ "2019.05.12", 17.9 };
		MedicalAnalysis* analysis3 = new BP{ "2019.05.23", 101, 75 };
		MedicalAnalysis* analysis4 = new BP{ "2019.06.03", 104, 81 };

		person->addAnalysis(analysis1);
		person->addAnalysis(analysis2);
		person->addAnalysis(analysis3);
		person->addAnalysis(analysis4);

		Console console{ person };
		console.runConsole();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}