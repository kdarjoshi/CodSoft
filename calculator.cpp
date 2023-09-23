#include <iostream>

using namespace std;

float calculate(float num1, float num2, char op) {
  switch (op) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      return num1 / num2;
    default:
      cout << "Invalid operator!" << endl;
      return 0;
  }
}

int main() {
  float num1, num2;
  char op;

  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  cout << "Enter an operator (+, -, *, /): ";
  cin >> op;

  float result = calculate(num1, num2, op);

  cout << "The result is: " << result << endl;

  return 0;
}
