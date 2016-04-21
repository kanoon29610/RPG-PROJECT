#include "head.h"

#ifndef STATUS_H
#define STATUS_H

class status{
	public:
		void setAtk(int);
		void setDef(int);
		void setHp(int);
		void setMaxhp(int);
		int getAtk();
		int	getDef();
		int getHp();
		int getMaxhp();
		void addAtk(int);
		void addDef(int);
		void addHp(int);
		void addMaxhp(int);
		void setAll(int, int, int);
		string getType();
		status(int,int,int);
		status(int);
		status();
		
	private:
		int atk;
		int def;
		int hp;
		int maxHp;
		string typeName = "STATUS";
	
};

#endif

