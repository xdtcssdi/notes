#ifndef __FACTORY__
#define __FACTORY__
#include <iostream>
#include <string>
using std::string;
class AbstractSportProduct
{
public:
	AbstractSportProduct(){
	}
	//抽象方法：
	virtual void printName()=0;
	virtual void play()=0;
};
//具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Basketball\n");
	}
	void play(){
		printf("Jungle play Basketball\n");
	}
};
 
//具体产品类Football
class Football :public AbstractSportProduct
{
public:
	Football(){
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Football\n");
	}
	void play(){
		printf("Jungle play Football\n");
	}
};
 
//具体产品类Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Volleyball\n");
	}
	void play(){
		printf("Jungle play Volleyball\n");
	}
};
class Factory
{
public:
	AbstractSportProduct *getSportProduct(string productName)
	{
		AbstractSportProduct *pro = NULL;
		if (productName == "Basketball"){
			pro = new Basketball();
		}
		else if (productName == "Football"){
			pro = new Football();
		}
		else if (productName == "Volleyball"){
			pro = new Volleyball();
		}
		return pro;
	}
};
#endif