// stdafx.cpp : source file that includes just the standard includes
// Mammals.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


Color::Color(color c) : m_Color(c)
{
}


Color::~Color()
{
}


Mammal::Mammal(unsigned age, double weight) : m_nAge(age), m_Weight(weight)
{
}


unsigned Mammal::getAge()
{
	return m_nAge;
}


double Mammal::getWeight()
{
	return m_Weight;
}


void Mammal::setAge(unsigned age)
{
	m_nAge = age;
	return;
}


void Mammal::setWeight(double weight)
{
	m_Weight = weight;
	return;
}


Mammal::~Mammal()
{
}


Dog::Dog(Color * C, bool isWild, unsigned age, double weight) : m_Color(*C), m_IsWild(isWild), Mammal(age, weight)
{
	delete C;
}


Color Dog::getColor()
{
	return m_Color;
}


bool Dog::getIsWild()
{
	return m_IsWild;
}


void Dog::setColor(Color color)
{
	m_Color = color;
}


void Dog::setIsWild(bool isWild)
{
	m_IsWild = isWild;
}


string Dog::yelp()
{
	return "Bark Bark Bark";
}


void Dog::display()
{
	cout << setw(6) << m_Color << " " << setw(6) << m_IsWild << " " << setw(3) << m_nAge << " " << setw(6) << m_Weight << endl;
	animalYelp(*this);
	return;
}


Dog::~Dog()
{
}


Cat::Cat(unsigned age, double weight) : Mammal(age, weight)
{
}


Color Cat::getColor()
{
	Color c(Color::_COLOR_UNDEFINED);
	return c;
}


bool Cat::getIsWild()
{
	return _ISWILD_UNDEFINED;
}


void Cat::setColor(Color)
{
	return;
}


void Cat::setIsWild(bool)
{
	return;
}


string Cat::yelp()
{
	return "Mew Miaow Miaou";
}


void Cat::display()
{
	cout << setw(6) << "N/A" << " " << setw(6) << "N/A" << " " << setw(3) << m_nAge << " " << setw(6) << m_Weight << endl;
	animalYelp(*this);
	return;
}


Cat::~Cat()
{
}


void animalYelp(Mammal& mammel)
{
	cout << mammel.yelp() << endl;
	return;
}


void animalYelp(Mammal * mammal)
{
	cout << mammal->yelp() << endl;
	return;
}


MyCin::MyCin()
{
}


template <typename T>
T MyCin::getNext(istream& inputStream)
{
	T next;
	inputStream >> next;
	return next;
}


MyCin::~MyCin()
{
}


ostream& operator <<(ostream& outputStream, Color& C)
{
	string next;
	switch (C.m_Color)
	{
	case Color::Brown:
		next = "Brown";
		break;
	case Color::Red:
		next = "Red";
		break;
	case Color::Orange:
		next = "Orange";
		break;
	case Color::Yellow:
		next = "Yellow";
		break;
	case Color::Green:
		next = "Green";
		break;
	case Color::Blue:
		next = "Blue";
		break;
	case Color::Violet:
		next = "Violet";
		break;
	case Color::Grey:
		next = "Grey";
		break;
	case Color::White:
		next = "White";
		break;
	case Color::Black:
		next = "Black";
		break;
	default:
		break;
	}
	if (C.m_Color != Color::_COLOR_UNDEFINED)
	{
		outputStream << next;
	}
	return outputStream;
}


istream& operator >>(istream& inputStream, Color& C)
{
	string next;
	inputStream >> next;
	if (next == "Brown")
	{
		C.m_Color = Color::Brown;
	}
	else if (next == "Red")
	{
		C.m_Color = Color::Red;
	}
	else if (next == "Orange")
	{
		C.m_Color = Color::Orange;
	}
	else if (next == "Yellow")
	{
		C.m_Color = Color::Yellow;
	}
	else if (next == "Green")
	{
		C.m_Color = Color::Green;
	}
	else if (next == "Blue")
	{
		C.m_Color = Color::Blue;
	}
	else if (next == "Violet")
	{
		C.m_Color = Color::Violet;
	}
	else if (next == "Grey")
	{
		C.m_Color = Color::Grey;
	}
	else if (next == "White")
	{
		C.m_Color = Color::White;
	}
	else if (next == "Black")
	{
		C.m_Color = Color::Black;
	}
	else
	{
		C.m_Color = Color::_COLOR_UNDEFINED;
	}
	return inputStream;
}

