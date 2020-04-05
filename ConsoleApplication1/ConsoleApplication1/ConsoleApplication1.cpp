#include <iostream>
#include<ilcplex/ilocplex.h>
ILOSTLBEGIN
int main()
{
	IloEnv env;
	IloModel model(env);
	IloNumVar x1(env, 0, 99, ILOINT);
	IloCplex cpl(model);
	IloConstraint cont,cont2;

	cont = (x1 * 5 >= 10);
	cont2 = (x1 >= 3);
	model.add(IloMinimize(env, x1 * 6));
	model.add(cont);
	model.add(cont2);
	cpl.solve();
	env.out() << cpl.getValue(x1) << endl << cpl.getObjValue() << endl;
	system("pause");
}
