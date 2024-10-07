#include <iostream>
#include <string>
#include <vector>
#include <functional>

// Модель - об'єкт, що містить дані
class UserModel {
public:
	std::string getUserName() const { return userName; }
	void setUserName(const std::string& name) { userName = name; }

private:
	std::string userName;
};

// Представлення - відповідальне за відображення даних
class UserView {
public:
	void displayUser(const std::string& name) {
		std::cout << "User: " << name << std::endl;
	}

	std::string getInput() {
		std::string name;
		std::cout << "Enter username: ";
		std::getline(std::cin, name);
		return name;
	}
};

// Контролер - зв'язує модель та представлення
class UserController {
public:
	UserController(UserModel& model, UserView& view)
		: model(model), view(view) {}

	void updateUser() {
		std::string name = view.getInput();
		model.setUserName(name);
	}

	void showUser() {
		view.displayUser(model.getUserName());
	}

private:
	UserModel& model;
	UserView& view;
};

int main() {
	UserModel model;
	UserView view;
	UserController controller(model, view);

	controller.updateUser(); // Отримати ім'я користувача
	controller.showUser();    // Відобразити ім'я користувача

	return 0;
}
