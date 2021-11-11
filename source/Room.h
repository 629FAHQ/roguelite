/**
룸과 통로는 structure라는 클래스를 상속받음.
structure는 맵 내에 생성되는 플레이어가 속할 수 있는 공간을 위한 클래스임.
*/
class Room : public Structure{
private:
	vector<*Monster> monsters, isBossRoom;
public:
	Room (int x, int y, int w, int h): Structure(x, y, w, h), monsters(0), isBossRoom(0) {}
	
	// 몬스터 목록에 몬스터를 추가한다.
	void addMonster() {}
	
	// 죽은 몬스터를 삭제한다.
	void delMonster() {}
	
	// 내 방 안에 있는 모든 몬스터들이 1턴 움직이도록 한다.
	void actMonster() {}
	
	// 방 안에 살아있는 몬스터가 없는지 검사한다.
	bool isClear() {}
};