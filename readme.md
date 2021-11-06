<!--https://dsc-sookmyung.tistory.com/24-->

# 1. 프로젝트 소개
## 1.1. 개발 목적
OOP에 대해 공부.

## 1.2. 개발 언어
C++

## 1.3. 무얼 만드나?
게임

## 1.4. 게임 구동 환경
콘솔창

## 1.5. 참고 사이트
[객체지향1](https://effectiveprogramming.tistory.com/entry/%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5%EC%9D%98-%EC%98%AC%EB%B0%94%EB%A5%B8-%EC%9D%B4%ED%95%B4-%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5-%EC%96%B8%EC%96%B4%EC%9D%98-%EB%8C%80%EB%91%90?category=660012)
[객체지향2](https://voidfunction-e.tistory.com/)
# 2. 게임 소개

## 2.1. 게임 장르
로그라이트


## 2.2. 게임 스토리
추후 작성 예정


## 2.3. 전체적인 게임 컨셉
게임 방식은 로그라이크 게임들과 유사함.
맵은 여러 타일들의 집합인 방으로 구성되어 있음. 
방의 종류는 두 가지로 보스가 있는 방과 그렇지 않은 방이 있음.
모든 타일의 위에는 랜덤한 종류의 마법 스크롤이 놓여 있을수 있고, 플레이어는 그 스크롤을 사용해 몬스터와 전투 할 수 있음.
스크롤을 사용할 시, 해당 속성에 대한 친화도가 증가하며 친화도는 속성의 능력에 긍정적인 영향을 줌.
또한, 직접 가보지 않았던 장소는 플레이어가 직접 간 후에 밝아짐.
	
	
	
## 2.4. 속성 시너지
내가 최근에 사용했던 속성과 지금 사용하려는 속성에 따라 여러 조합이 있음.
최대 이전에 사용했던 2개의 속성까지 지금 행하는 속성 공격에 영향을 줄 수 있음.
조합의 효과는 무조건 긍정적인것은 아니며 속성 친화도에 비례하여 강화/상쇄될 수 있음.



## 2.5. 전투 방식
### vs 일반 몬스터
일반 몬스터와의 전투는 간략화된 턴제로 진행 되며 플레이어가 2번 행동하면 몬스터는 1번 움직이는 식임.
플레이어는 매 행동마다 상, 하, 좌, 우, 공격 5가지 행동 중 하나를 취할 수 있으며 스크롤을 이용한 공격을 행했을 시 해당 스크롤의 속성은 노말로 변경됨.
플레이어가 몬스터로부터 공격 받았을 시 플레이어는 데미지를 입으며, 플레이어의 턴-카운트는 1 감소함.

### vs 보스 몬스터
보스전도 일반 몬스터와의 전투와 유사한 방식으로 진행되지만, 일반 몬스터에 비해 체력, 공격력이 월등히 높음. 또한 한 방에 한 개체만 생성됨.


## 2.6. 게임을 끝내는 방법

### 죽음
플레이어의 체력이 0이되면 플레이어는 죽으며 그대로 게임이 종료됨.

### 3번째 스테이지 보스 처치 시
총 3개의 스테이지의 최종 보스를 처치했으므로 게임이 클리어 됨.

## 2.7. 생각해볼 문제 & 아이디어 노트
** [Idea] 클리어된 방의 스크롤은 모두 비활성화 되어야 한다.**  
➝ 비전투 상황에서도 속성 친화도 및 시너지 조합 주작이 가능하므로.

** [Idea] 마나를 수급할만한 장치를 만들어야 한다. **

** [Idea] 플레이어가 마나를 모두 사용한 경우 플레이어는 스크롤을 통한 속성 공격을 할 수 없음. **


	
## 2.8. 속성의 종류
| 속성명 | 기본 공격력 | 설명 |
| - | - | - |
|화염| 20 | 전방 스플래시 공격, 중첩 가능 |
|전기| 10 | 스태틱 효과 |
|물| 5 |  |
|바람| 10 | 사거리 증가 |
|빛| 10 | 무한한 직선 공격 |
|어둠| 10 | 마나 흡수 |
|노말| 15 | 효과 없음 |

## 2.9. 속성 조합 표
| 속성 | 친화도 | 속성 | 시너지 | 효과 | 내용 |
|-|-|-|-|-|-|
|화염| | | | |
|전기| | | | |
|물| | | | |
|바람| | | | |
|빛| | | | |
|어둠| | | | |
|노말| | | | |
