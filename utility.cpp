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

vector<Town>* load::getTownData(){
	return &townData;
}
Town load::getTownData(int townID){
	return townData[townID];
}

vector<Room>* load::getRoomData(){
	return &roomData;
}
Room load::getRoomData(int roomID){
	return roomData[roomID];
}

vector<Dungeon>* load::getDungeonData(){
	return &dungeonData;
}
Dungeon load::getDungeonData(int dunID){
	return dungeonData[dunID];
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

