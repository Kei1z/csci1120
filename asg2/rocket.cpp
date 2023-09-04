// lee ho kong 1155149106 leehokong@gmail.com
#include <iostream>
using namespace std;

void rocket(int h, int b, int w, int t) {
	// for loop for the head of the rocket
	for (int k = 1; k <= w + h + 1; k++) {
		cout << " ";
	}
	cout << "|";

	for (int k = 1; k <= w + h + 1; k++) {
		cout << " ";
	}
	cout << "\n";

	// for loop for the head of the rocket
	for (int i = 1; i <= h; i++) {
		for (int j = i; j <= h + w; j++) {
			cout << " ";
		}
		cout << "/";

		for (int j = 0; j < i - 1; j++) {
			cout << "*";
		}
		cout << "*";

		for (int j = 0; j < i - 1; j++) {
			cout << "*";
		}

		cout << "\\";
		for (int j = i; j <= h + w; j++) {
			cout << " ";
		}
		cout << "\n";
	}



	// middle part of the rokcet
	for (int k = 1; k <= w; k++) {
		cout << " ";
	}
	cout << "+";
	for (int k = 1; k <= 2 * h + 1; k++) {
		cout << "-";
	}
	cout << "+";
	for (int k = 1; k <= w; k++) {
		cout << " ";
	}
	cout << "\n";

	for (int i = 1; i <= b; i++) {
		//cout << i;
		//cout << (b + 1) / 2;
		if (i <= b / 2) {
			for (int j = 1; j <= w; j++) {

				cout << " ";
			}
		}
		else {
			for (int j = 1; j <= w; j++) {
				cout << "/";
			}
		}
		cout << "|";
		for (int j = 1; j <= 2 * h + 1; j++) {
			cout << ".";
		}
		cout << "|";
		if (i <= b / 2) {
			for (int j = 1; j <= w; j++) {
				cout << " ";
			}
		}
		else {
			for (int j = 1; j <= w; j++) {
				cout << "\\";
			}
		}
		cout << "\n";
	}

	for (int k = 1; k <= w; k++) {
		cout << " ";
	}
	cout << "+";
	for (int k = 1; k <= 2 * h + 1; k++) {
		cout << "-";
	}
	cout << "+";
	for (int k = 1; k <= w; k++) {
		cout << " ";
	}
	cout << "\n";

	//tail part of the rocket

	for (int i = (t + 1) / 2; i > 0; i--) {
		for (int j = 1; j <= w; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i + h - t + 1; j++) {
			cout << " ";
		}
		for (int j = 1; j <= t - i; j++) {
			cout << "*";
		}
		cout << "*";
		for (int j = 1; j <= t - i; j++) {
			cout << "*";
		}
		for (int j = 1; j <= i + h - t + 1; j++) {
			cout << " ";
		}
		for (int j = 1; j <= w; j++) {
			cout << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= w; j++) {
			cout << " ";
		}
		for (int j = i + h - t + 1; j > 0; j--) {
			cout << " ";
		}
		for (int j = i; j < t; j++) {
			cout << "*";
		}
		cout << "*";
		for (int j = i; j < t; j++) {
			cout << "*";
		}
		for (int j = i + h - t + 1; j > 0; j--) {
			cout << " ";
		}
		for (int j = 1; j <= w; j++) {
			cout << " ";
		}
		cout << "\n";
	}



}
void printnum(int num) {
	cout << num;
}

int main() {
	int head, body, wing, tail;
	bool checker = true;
	while (checker) {
		cout << "Enter h, b, w, t: ";
		cin >> head >> body >> wing >> tail; // get the variable
		//printnum(tail);
		if (head < 1 || body < 2 || wing < 1 || tail <2 || (2 * tail - 1) >(2 * head + 3)) {
			continue;
		}
		else {
			rocket(head,body,wing,tail);
			checker = false;
		}
	}
	

	



}

