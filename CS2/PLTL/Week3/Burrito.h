#include "string"

using namespace std;

class Burrito
{
public:
	
	// Constructor. 
	// Creates a burrito with the specified ingredients.
	Burrito(string m, bool cheese){
		meatType=m;
		hasCheese=cheese;
	}

	// Constructor. 
	// Creates a burrito with no (Nada) meat and no cheese.
	Burrito(){
		meatType="Nada";
		hasCheese=false;
	}

	// Changes the burrito's meat to the parameter meat.
	void change_meat(string m){
		meatType=m;
	}

	// Adds/removes cheese to/from the burrito.
	void add_cheese(){
		hasCheese=true;
	}
	void remove_cheese(){
		hasCheese=false;
	}

	// Returns the burrito's current meat/cheese
	string meat(){
		return meatType;
	}
	bool cheese(){
		return hasCheese;
	}

	// Computes the price.
	// A burrito with no meat/cheese costs $2.
	// Cheese is $1 extra.
	// Meat costs $2, and Asada is $1 extra. 
	int price(){
		int prc =2;
		if (hasCheese){
			prc+=1;
		}
		if (!(meatType=="Nada")){
			prc+=2;
		}
		if (meatType=="Asada"){
			prc+=1;
		}
		return prc;
	}

private:
	string meatType; // meatType could be any of these: Pollo, Asada, AlPastor, Nada, etc
	bool hasCheese;
};