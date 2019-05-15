#include "Console.h"

// Exam 2 - Fine cargo

int main() {
	Repository repoAll{};
	Repository repoSpecialStorage{};

	Controller controller{ &repoAll, &repoSpecialStorage };

	controller.addPainting("Da Vinci", "Mona Lisa", 1503);
	controller.addPainting("Da Vinci", "Virtuvian Man", 1490);
	controller.addPainting("Van Gogh", "The Starry Night", 1889);
	
	Console console{ &controller };
	console.runConsole();

	return 0;
}