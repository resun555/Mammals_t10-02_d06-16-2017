// Mammals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	Dog someDog(new Color((Color::color)(1 + rand() % 10)), (bool)(rand() % 2), (unsigned)(rand() % 10), (double)(rand() % 10));
	Cat someCat((unsigned)(rand() % 10), (double)(rand() % 10));
	cout << setw(6) << "Color" << " " << setw(6) << "IsWild" << " " << setw(3) << "Age" << " " << setw(6) << "Weight" << endl << endl;
	someDog.display();
	someCat.display();
	cout << "SET PROPERTIES OF SOME DOG" << endl;
	cout << "\tColor: " << endl << "\t\t";
	someDog.setColor(MyCin::getNext<Color>());
	cout << "\tIsWild: " << endl << "\t\t";
	someDog.setIsWild(MyCin::getNext<bool>());
	cout << "\tAge: " << endl << "\t\t";
	someDog.setAge(MyCin::getNext<unsigned>());
	cout << "\tWeight: " << endl << "\t\t";
	someDog.setWeight(MyCin::getNext<double>());
	someDog.display();
	cout << "SET PROPERTIES OF SOME CAT" << endl;
	cout << "\tAge: " << endl << "\t\t";
	someCat.setAge(MyCin::getNext<unsigned>());
	cout << "\tWeight: " << endl << "\t\t";
	someCat.setWeight(MyCin::getNext<double>());
	someCat.display();
	cout << "============================" << endl;

	const size_t capacity = 100U;
	Mammal ** pMammal = new Mammal *[capacity];
	cout << setw(6) << "Color" << " " << setw(6) << "IsWild" << " " << setw(3) << "Age" << " " << setw(6) << "Weight" << endl << endl;
	srand((unsigned)time(0));
	animal random = dog;
	for (size_t i = 0; i < capacity; i++)
	{
		random = (animal)(1 + rand() % 2);
		switch (random)
		{
		case dog:
			pMammal[i] = new Dog(new Color((Color::color)(1 + rand() % 10)), (bool)(rand() % 2), (unsigned)(rand() % 10), (double)(rand() % 10));
			cout << setw(6) << pMammal[i]->getColor() << " " << setw(6) << pMammal[i]->getIsWild() << " " << setw(3) << pMammal[i]->getAge() << " " << setw(6) << pMammal[i]->getWeight() << endl;
			break;
		case cat:
			pMammal[i] = new Cat((unsigned)(rand() % 10), (double)(rand() % 10));
			cout << setw(6) << "N/A" << " " << setw(6) << "N/A" << " " << setw(3) << pMammal[i]->getAge() << " " << setw(6) << pMammal[i]->getWeight() << endl;
			break;
		default:
			break;
		}
		animalYelp(pMammal[i]);
	}
	for (size_t i = 0; i < capacity; i++)
	{
		delete pMammal[i];
	}
	delete pMammal;
    return 0;
}

