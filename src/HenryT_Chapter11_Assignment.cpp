//============================================================================
// Name        : HenryT_Chapter11_Assignment.cpp
// Author      : Henry Timmons
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;
struct CandyBar{
	string candyBarName;
	float candyPrice;
	int numberOfBars;
	int ID;


};
void clearCin(void){
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

int main() {
	CandyBar Bar1;
	int userInput = 0;
	vector<CandyBar> candyBarVector;
	float userMoneyInput = 0.00;
	float changeMoney = 0.00;
	float userInputMoneyTotal = 0.00;
	float totalChange = 0.00;

	Bar1.ID = 0;
	Bar1.candyBarName = "Butter Finger";
	Bar1.candyPrice = .95;
	Bar1.numberOfBars = 8;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 1;
	Bar1.candyBarName = "Milky Way";
	Bar1.candyPrice = .80;
	Bar1.numberOfBars = 3;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 2;
	Bar1.candyBarName = "Hershey Milk Chocolate";
	Bar1.candyPrice = .70;
	Bar1.numberOfBars = 5;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 3;
	Bar1.candyBarName = "Milk Duds";
	Bar1.candyPrice = .60;
	Bar1.numberOfBars = 9;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 4;
	Bar1.candyBarName = "Trolli Snakes";
	Bar1.candyPrice = 1.00;
	Bar1.numberOfBars = 2;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 5;
	Bar1.candyBarName = "Skittles";
	Bar1.candyPrice = .85;
	Bar1.numberOfBars = 7;
	candyBarVector.push_back(Bar1);
	Bar1.ID = 6;
	Bar1.candyBarName = "Dove Milk Chocolate";
	Bar1.candyPrice = .95;
	Bar1.numberOfBars = 5;
	candyBarVector.push_back(Bar1);


	while(userInput != -999){
		cout << '\n' << "Vending Machine Contents" << '\n';
		cout << setw(2) << "ID" << setw(15) << "Candy Bar" << setw(21) << right << "Price" << setw(10) << "Quantity" << endl;//lines 73-78 print the menu
		cout << setw(2) << "--" << setw(15) << "---------" << setw(21) << right << "-----" << setw(10) << "--------" << endl;
		for(int i = 0; i < candyBarVector.size(); i++){
			cout << setw(8) << left << i << setw(25)  << candyBarVector[i].candyBarName << fixed <<setprecision(2) << right << "$" << candyBarVector[i].candyPrice << setw(10) << candyBarVector[i].numberOfBars << endl;

		}
		cout << "Enter the candy bar ID you would like to purchase.(-999 to quit): ";
					cin >> userInput;
					clearCin();
					cout << '\n';
			if(userInput == -999){
				break;
			}else if(userInput < 0 || (userInput > 6 && userInput != -999)){
				cout << "**Error please enter a value through 0-6" << endl;
			}
		for(int j = 0; j < candyBarVector.size(); j++){
			if(userInput == candyBarVector[j].ID){
				if(candyBarVector[j].numberOfBars == 0){
					cout << "**Sorry no more " << candyBarVector[j].candyBarName << " available, why not try a different candy bar?" << endl;
				}else{
					cout << "How much money do you want to put into the machine to buy a " << candyBarVector[j].candyBarName << ": ";
					cin >> userMoneyInput;
					clearCin();
					cout << '\n';
					if (userMoneyInput <= 0.00 || userMoneyInput > 1.00 ){ 					//checks to make sure the amount entered is between 0 and 1
								cout << "**Error please enter an amount of money between $0 and $1" << endl;
							}else if(userMoneyInput >= candyBarVector[j].candyPrice){ 			//checks to see if the amount entered can purchase the candy bar they want
								changeMoney = userMoneyInput - candyBarVector[j].candyPrice;//calculates change
								candyBarVector[j].numberOfBars--;							//subtracts 1 from the vedning machine
								userInputMoneyTotal += userMoneyInput;
								totalChange += changeMoney;
								cout << "You've purchased a " << candyBarVector[j].candyBarName <<" and your change is " << "$" << changeMoney << endl;
							}else if(userMoneyInput < candyBarVector[j].candyPrice){		//checks to see if there is enough money to purchase the candy bar selected
								cout << "**That is not enough money to buy a " << candyBarVector[j].candyBarName << ", " << "please insert more money" << endl;
						}//else if check enough money
					}//else check of quantity
				}//if input == ID
			}//for j loop
		}//while
	cout << "Thank you for your purchases, the total amount of money you spent today is $" << userInputMoneyTotal - totalChange << endl;
	cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
	return 0;
}
