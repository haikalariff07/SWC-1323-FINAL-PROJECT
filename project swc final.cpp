// Home Declaration
#include <iostream>
#include <string>
using namespace std;

// Array Declaration
int transactionNo[50];
int quantitySold[50];
double pricePerUnit[50];
string customerName[50];
string cookieType[50];

// Set Count to 0
int countTransaction = 0;

// Starts Record Sales Function
void recordSales(){
     	if (countTransaction < 50)
    {
        cout << "Enter the transaction detail: " << endl;
        // User start enter detail about customer
        cout << "Transaction No: ";
        cin >> transactionNo[countTransaction];
        // to check the transactionNo not less than 0
        if (transactionNo[countTransaction] < 0)
        {
            cout << "Invalid Input. Transaction No must be greater than 0 \n";
            return recordSales();
        }
        cin.ignore();

        cout << "Cookie Type: ";
        cin >> cookieType[countTransaction];

        cout << "Quantity sold: ";
        cin >> quantitySold[countTransaction];
        if (quantitySold[countTransaction] < 0)
        {
            cout << "Invalid Input. Quantity must be greater than 0 \n";
            return recordSales();
        }

        cout << "Price per unit: ";
        cin >> pricePerUnit[countTransaction];
        cin.ignore();
        if (pricePerUnit[countTransaction] < 0)
        {
            cout << "Invalid Input. Price per unit must be greater than 0 \n";
            return recordSales();
        }

         cout << "\n\n";
        cout << "PLEASE ENTER NAME : ";
        getline(cin, customerName[countTransaction]);
        countTransaction++;
    }
    else
    {
        cout << "Transaction maximum reached" << endl;
    }
} // Record Sales Function Ends


// Starts Calculate Total Revenue Function
double calculateTotalRevenue(){
	double total = 0.0;
    for (int i = 0; i < countTransaction; i++)
    {
        /* i is for index
        total declaration is to sum for all quantitySold * pricePerUnit depends on which index*/
        total += quantitySold[i] * pricePerUnit[i];
    }
    return total;

} // Calculate Total Revenue Ends

// Starts Display Sales Records Function
void displaySalesRecords(){
     if (countTransaction < 1)
    {
        cout << "There is no sale recorded. ";
    }
    else
    {
        cout << "Sales Records :" << endl;
        for (int i = 0; i < countTransaction; i++){
		
		// Using For Loop to display all data that contains infomation inside th array
        cout << "             Transaction No : " << transactionNo[i] << endl;
		cout << "Cookie Type : " << cookieType[i] << endl;
		cout << "Quantity : " << quantitySold[i] << endl;
		cout << "Price per unit : RM" << pricePerUnit[i] << endl; 
		cout << "Customer's name : " << customerName[i] << endl;
		cout << "__________________________________________"<< endl;	
		}
        
    }

}// Calculate Total Revenue Ends 

// Starts Find Sales Records Function
void findSalesRecords(string findCustomer){
     cout << "Sales Records for Customer " << findCustomer << ":" << endl;
	
	// Function asks for the CustomerName to find data in the Record Sales
    bool foundCustomer = false;
    for (int i = 0; i < countTransaction; i++)
    {
        if (customerName[i] == findCustomer)
        {
    	foundCustomer = true;
        cout << "Transaction No : " << transactionNo[i] << endl;
		cout << "Cookie Type : " << cookieType[i] << endl;
		cout << "Quantity : " << quantitySold[i] << endl;
		cout << "Price per unit : RM " << pricePerUnit[i] << endl; 
    }
    if (!foundCustomer)
    {
        cout << "No sales recorded for customer :" << customerName << "\n" << endl;
    }
	}

}// Find Sales Records Ends

// Starts Update Sales Records Fucntion
void updateSalesRecords(int transUp){
	
    for (int i = 0; i < countTransaction; i++)
    {
        if (transactionNo[i] == transUp)
        {
            cout << "Enter new detail " << transUp << ": " << endl;

            // entering all new data for the customer detail
            cout << "Cookie type: ";
            cin >> cookieType[i];

            cout << "Quantity Sold: ";
            cin >> quantitySold[i];

            cout << "Price Per Unit: ";
            cin >> pricePerUnit[i];
            cin.ignore();

            cout << "Customer Name: ";
            getline(cin, customerName[i]);

            cout << "Sales record updated successfully.\n";
            return;
        }
    }
    cout << "The transaction not found in the system" << endl;
    cout << "\n";
}// Update Sales Records Ends

int main() {

int choice;

cout << "________________________________________" << endl;
cout << "|\tWELCOME TO AD & AI BAKERY\t|" << endl;
cout << "________________________________________" << endl;

// using do while loop to complete the system that will ask user to choose the choices until user key in number '6'
do{
	cout << "\t1. Record Sales. " << endl;
	cout << "\t2. Calculate Total Revenue. " << endl;
	cout << "\t3. Display Sales Records. " << endl;
	cout << "\t4. Find Sales Customer. " << endl;
	cout << "\t5. Update Sales Record. " << endl;
	cout << "\t6. Exit. " << endl;
	cout << "\n ";
	
	cout << "Choice : ";
	cin >> choice;
	
	
	switch (choice){
		
		case 1:
			recordSales();
			break;
		case 2:
			cout << "Total Revenue : RM " << calculateTotalRevenue() << endl;
			break;
		case 3:
			displaySalesRecords();
			break;
		case 4:{
			string findCustomer;
			cout << "Enter Customer's Name : ";
			cin.ignore();
			getline(cin, findCustomer);
			// user needs to enter the exact same data in the array. P/S : check the capitalization.
			findSalesRecords(findCustomer);
			
		}
		break;		
		case 5:{
			int transUp;
			cout << "Enter transaction number : ";
			cin >> transUp;
			// uses transactionNo to successfully call the updateSalesRecords() void function.
			updateSalesRecords(transUp);
			
		}
		break;		
		case 6:
			cout << "Program Terminated :).." << endl;
			break;
		default:
			cout << "Input Doesn't Exist. Please Try Again :)" << endl;
	}
	
}while (choice != 6);

    return 0;
}// Program Ends
