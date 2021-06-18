//
//  main.cpp
//  8_Static_Member
//
//  Created by 세광 on 2021/06/18.
//

/*
 정적 멤버: class에 속하지만, 객체 별로 할당되지 않고 class의 모든 객체가 공유하는 멤버
 멤버 변수가 정적(static)으로 선언되면, 해당 class의 모든 객체에 대해 하나의 데이터만이 유지 관리됨
 
 정적 멤버 변수는 class 영역에서 선언되지만, 정의는 파일 영역에서 수행
 이러한 정적 멤버 변수는 외부 연결(external linkage)을 가지므로, 여러 파일에서 접근할 수 있음
 
 정적 멤버 변수에도 class 멤버의 접근 제한 규칙이 적용되므로, class의 멤버 함수나 프렌드만이 접근할 수 있음
 정적 멤버 변수를 외부에서도 접근할 수 있도록 하려면, 정적 멤버 변수를 public 영역에 선언
 
 전역 변수 및 전역 함수의 경우 객체 지향 프로그래밍에서 최대한 지양해야 함
 특정 class와 관련이 있는 모든 변수나 함수는 정적으로 선언하여 class 안에 넣도록 해야 함
 전역 함수(전역에서 쓰고 싶은 함수)가 class와 밀접한 관련이 있고 private field 안의 정적 메서드나 정적 변수에 접근하고 싶을 때 static 사용
 */

#include <iostream>

using namespace std;

class Color {
public:
    Color() : r(0), g(0), b(0), id(idCounter++) { }
    Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) { }
    
    float GetR() { return r; }
    float GetG() { return g; }
    float GetB() { return b; }
    float GetId() { return id; }
    
    static Color MixColors(Color a, Color b) {
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
    }
    
    static int idCounter; // 정적으로 선언되었을 경우 class 안에서 초기 값을 줄 수 없음(값을 대입할 수 없음)
    
private:
    float r, g, b;
    int id;
};

int Color::idCounter = 1;

int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);
    Color purple = Color::MixColors(blue, red);
    // Color purple = blue.MixColors(blue, red); // 정적 메서드임에도 불구하고 어떤 객체에 포함되어 있는 형태로도 사용할 수 있음
    
    cout << "r: " << purple.GetR() << ", g: " << purple.GetG() << ", b: " << purple.GetR() << endl;
    cout << "blue.GetId() = " << blue.GetId() << endl;
    cout << "red.GetId() = " << red.GetId() << endl;
    cout << "purple.GetId() = " << purple.GetId() << endl;
}
