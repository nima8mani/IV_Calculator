#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

//mashin hesab
//ilia varmaziyar

double daryaft_meghdar(string matn_chap){
    double meghdar;
    bool dorost = false;

    while(!dorost){
        cout << matn_chap;
        string reshte;
        getline(cin , reshte);
        stringstream jaryan_adad(reshte);
        string ezafe;

        if((jaryan_adad >> meghdar) && !(jaryan_adad >> ezafe)) {
            dorost = true;
        }
		 else{
            cout << "The input is incorrect. Please try again." << endl;
        }
    }

    return meghdar;
}
void amal_jam(){
    double adad1 = daryaft_meghdar("Enter first number: ");
    double adad2 = daryaft_meghdar("Enter second number: ");
    cout << "Result: " << adad1+adad2 << endl;
}
void amal_tafrigh(){
    double adad1 = daryaft_meghdar("Enter first number: ");
    double adad2 = daryaft_meghdar("Enter second number: ");
    cout << "Result: " << adad1-adad2 << endl;
}
void amal_zarb(){
    double adad1 = daryaft_meghdar("Enter first number: ");
    double adad2 = daryaft_meghdar("Enter second number: ");
    cout << "Result: " << adad1*adad2 << endl;
}
void amal_taghsim(){
    double maghsoom = daryaft_meghdar("Enter first number: ");
    double maghsoom_aleyh = daryaft_meghdar("Enter second number: ");
    if(maghsoom_aleyh == 0){
        cout << "Division by zero is not possible!" << endl;
    }
    else{
        cout << "Result: " << maghsoom / maghsoom_aleyh << endl;
    }
}
void amal_tavan(){
    double adad_paye =daryaft_meghdar("Enter base (a): ");
    int adad_tavan;
    double temp_t;
    bool dorost = false;

    while(!dorost){
        cout << "Enter exponent (b-integer): ";
        string reshte_tavan;
        getline(cin , reshte_tavan);
        stringstream jaryan_tavan(reshte_tavan);
        string ezafe;
        if((jaryan_tavan >> temp_t) && !(jaryan_tavan >> ezafe)
			&& temp_t == (int)temp_t){
            adad_tavan = (int)temp_t;
            dorost = true;
        }
		 else{
            cout << "The input is incorrect. Please try again." << endl;
        }
    }
    if(adad_paye==0 && adad_tavan<0){
        cout << "Division by zero is not possible!" << endl;
        return;
    }
    double hasel = 1.0;
    if(adad_tavan >= 0){
        for(int k=0; k<adad_tavan; k++){
            hasel *= adad_paye;
        }
    }
	else{
        for(int k=0; k<-adad_tavan; k++){
            hasel *= adad_paye;
        }
        hasel = 1.0/hasel;
    }
    cout << "Result: " << hasel << endl;
}
void amal_jazr(){
    double value = daryaft_meghdar("Enter a number: ");
    if(value<0){
        cout << "A negative number does not have a square root." << endl;
    }
	 else{
        cout << "Result: " << sqrt(value) << endl;
    }
}
void amal_log(){
    double base_val = daryaft_meghdar("Enter base: ");
    double num_val =daryaft_meghdar("Enter number: ");
    if(base_val<=0 || num_val<=0 || base_val==1){
        cout << "The base and the number must both be positive values." << endl;
    }
	 else{
        cout << "Result: " << log10(num_val) / log10(base_val) << endl;
    }
}
void amal_mosalasat(int entekhab){
    double daraje = daryaft_meghdar("Enter angle in degrees: ");
    double radian = daraje * 3.14159265358979323846 / 180.0;

    if(entekhab==8){
        cout << "Result (Sin): " << sin(radian) << endl;
    }
	 else if(entekhab==9){
        cout << "Result (Cos): " << cos(radian) << endl;
    }
	else if(entekhab==10){
        if(fmod(daraje-90 , 180) == 0){
            cout << "The tangent of this angle is undefined." << endl;
        }
		else{
            cout << "Result (Tan): " << tan(radian) << endl;
        }
    }
}
int main(){

    int bakhsh_menu = 0;
    do{
        cout << endl << "----------------------------------------" << endl;
        cout << "           Advanced Calculator" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl;
        cout << "5. Exponentiation" << endl << "6. Square Root" << endl << "7. Logarithm" << endl;
        cout << "8. Sin()" << endl << "9. Cos()" << endl << "10. Tan()" << endl << "11. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Please select an option: ";

        string matn_voroodi;
        getline(cin , matn_voroodi);
        stringstream jaryan(matn_voroodi);
        double temp_bakhsh;
        string ezafe;
        if(!(jaryan >> temp_bakhsh) || (jaryan >> ezafe) || temp_bakhsh != (int)temp_bakhsh){
            cout << "The input is incorrect. Please try again." << endl;
            continue;
        }
        bakhsh_menu = (int)temp_bakhsh;
        switch(bakhsh_menu){
            case 1: amal_jam();
			 break;
            case 2: amal_tafrigh();
			 break;
            case 3: amal_zarb();
			 break;
            case 4: amal_taghsim();
			 break;
            case 5: amal_tavan();
			 break;
            case 6: amal_jazr();
			 break;
            case 7: amal_log();
			 break;
            case 8:
            case 9:
            case 10: amal_mosalasat(bakhsh_menu);
			 break;
            case 11:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:  cout << "The input is incorrect. Please try again." << endl;
        }
    }
	while(bakhsh_menu != 11);
    return 0;
}
