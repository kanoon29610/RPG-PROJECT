#include "head.h"
#include "GAME.h"

int main(){
	GAME *core = new GAME("BABARA");
	cout << "Hi I am " << core->getPlayer()->getName() << endl;
	cout << "This is my stat ATK = " << core->getPlayer()->getStat().getAtk() <<" DEF = "<<core->getPlayer()->getStat().getDef()<<" MAXHP = "<<core->getPlayer()->getStat().getMaxhp();
	cout << "\n Data size " << core->getType()<<endl;
	core->loadItemData();
	for(int i=0;i<core->getItemData()->size();i++){
		core->getItemData(i).printItem();
	}
//	getch();
	return 0;
}
