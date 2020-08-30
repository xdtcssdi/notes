#include <iostream>
#include "Factory.h"
 
 /*
简单工厂模式的优点在于：
	工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
	客户只需要知道对应产品的参数即可，参数一般简单好记，如数字、字符或者字符串等。
缺点：
	违背了开闭原则（对扩展开放，对修改关闭），即在扩展功能时修改了既有的代码
 */
int main()
{
	printf("简单工厂模式\n");
	
	//定义工厂类对象
	Factory *fac = new Factory();
	AbstractSportProduct *product = NULL;
 
	product = fac->getSportProduct("Basketball");
    product->play();
    product->printName();
	product = fac->getSportProduct("Football");
    product->play();
    product->printName();
	product = fac->getSportProduct("Volleyball");	
    product->play();
    product->printName();
	return 0;
}