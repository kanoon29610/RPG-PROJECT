#include "utility.h"

template <class T>
void load::addData(vector<T> *data,T obj){
	data->push_back(obj);
}

vector<Item>* load::getItemData(){
	return &itemData;
}
Item load::getItemData(int itemID){
	return itemData[itemID];
}

vector<monster>* load::getMonsterData(){
	return &monsterData;
}
monster load::getMonsterData(int monID){
	return monsterData[monID];
}

vector<skill>* load::getSkillData(){
	return &skillData;
}
skill load::getSkillData(int skillID){
	return skillData[skillID];
}

vector<passive>* load::getPassiveData(){
	return &passiveData;
}
passive load::getPassiveData(int passID){
	return passiveData[passID];
}

vector<attack>* load::getAttackData(){
	return &attackData;
}
attack load::getAttackData(int attackID){
	return attackData[attackID];
}

vector<monsterMove>* load::getMonAttackData(){
	return &monAttackData;
}
monsterMove load::getMonAttackData(int monAttID){
	return monAttackData[monAttID];
}

vector<Place>* load::getPlaceData(){
	return &placeData;
}
Place load::getPlaceData(int placeID){
	return placeData[placeID];
}

void load::loadItemData(){
	ifstream src;
	src.open("data/ITEM.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
			
			Item *obj = new Item();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int SP = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int BP = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string type = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int atk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int def = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string skill = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int attIndex = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string desc = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,SP,BP,type,atk,def,hp,skill,attIndex,desc);
			
			load::addData(load::getItemData(),*obj);

		}
	}
}

void load::loadAttackData(){
	ifstream src;
	src.open("data/ATTACK.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			attack *obj = new attack();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double DmgF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hit = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hitC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int criC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double criF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string desc = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,DmgF,hit,hitC,criC,criF,desc);
			
			load::addData(load::getAttackData(),*obj);
		}
	}
}

void load::loadMonsterData(){
	ifstream src;
	src.open("data/MONSTER.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			monster *obj = new monster();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int atk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int def = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string cls = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int sk = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string move = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,atk,def,hp,cls,sk,move);
			
			load::addData(load::getMonsterData(),*obj);
		}
	}
}

void load::loadMonAttackData(){
	ifstream src;
	src.open("data/MONSTERMOVE.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			monsterMove *obj = new monsterMove();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double DmgF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hit = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int hitC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int criC = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			double criF = atof( line.substr(0,line.find_first_of(',')).c_str() );
			int mhp = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int php = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int p = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			int c = atoi( line.substr(0,line.find_first_of('\0')).c_str() );

			obj->setAll(id,name,DmgF,hit,hitC,criC,criF,mhp,php,p,c);
			
			load::addData(load::getMonAttackData(),*obj);
		}
	}
}

void load::loadPlaceData(){
	ifstream src;
	src.open("data/PLACE.txt");
	string line;
	while(getline(src, line)){// .substr(0,textline.find_first_of(':'))
		if(line.substr(0,line.find_first_of('/')+1) != "/"){
		
			Place *obj = new Place();
			int id = atoi( line.substr(0,line.find_first_of(',')).c_str() );
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string name = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string type = line.substr(0,line.find_first_of(','));
			line = line.substr(line.find_first_of(',')+1,line.find_first_of('\0'));
			string dest = line.substr(0,line.find_first_of('\0'));

			obj->setAll(id,name,type,dest);
			
			load::addData(load::getPlaceData(),*obj);
		}
	}
}


