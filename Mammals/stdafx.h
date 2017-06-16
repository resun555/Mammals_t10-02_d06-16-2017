// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class Color
{
public:
	enum color
	{
		Brown,
		Red,
		Orange,
		Yellow,
		Green,
		Blue,
		Violet,
		Grey,
		White,
		Black,
		_COLOR_UNDEFINED
	} m_Color;
	Color(color = Brown);
	~Color();

private:

};

using namespace std;
using ::Color;

#ifndef _ISWILD_UNDEFINED
#define _ISWILD_UNDEFINED false
#endif // !_ISWILD_UNDEFINED

class Mammal
{
public:
	Mammal(unsigned = 0, double = 0.);
	virtual Color getColor() = 0;
	virtual bool getIsWild() = 0;
	unsigned getAge();
	double getWeight();
	virtual void setColor(Color) = 0;
	virtual void setIsWild(bool) = 0;
	void setAge(unsigned);
	void setWeight(double);
	virtual string yelp() = 0;
	virtual void display() = 0;
	virtual ~Mammal();

private:

protected:
	unsigned m_nAge;
	double m_Weight;

};

class Dog : public Mammal
{
public:
	Dog(Color * = new Color(Color::Brown), bool = false, unsigned = 0, double = 0.);
	virtual Color getColor();
	virtual bool getIsWild();
	virtual void setColor(Color);
	virtual void setIsWild(bool);
	virtual string yelp();
	virtual void display();
	virtual ~Dog();

private:
	Color m_Color;
	bool m_IsWild;

};

class Cat : public Mammal
{
public:
	Cat(unsigned = 0, double = 0.);
	virtual Color getColor();
	virtual bool getIsWild();
	virtual void setColor(Color);
	virtual void setIsWild(bool);
	virtual string yelp();
	virtual void display();
	virtual ~Cat();

private:

};

enum animal
{
	dog, 
	cat
};

void animalYelp(Mammal&);

void animalYelp(Mammal *);

class MyCin
{
public:
	MyCin();
	template <typename T>
	static T getNext(istream& = cin);
	~MyCin();

private:

};

ostream& operator <<(ostream&, Color&);

istream& operator >>(istream&, Color&);
