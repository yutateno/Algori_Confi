#include <iostream>



// 列挙型の基礎となる型を変更
enum class EnumChangeType : char { Red = 'a', Green, Blue };



// 可変長テンプレートの要素数を求める
template<class... Types>
struct S {
	static const size_t count = sizeof...(Types);
};



// 抽象クラス(抽象クラスはのオブジェクトは生成することができない
class Shape {
public:
	virtual void Draw(int x, int y, int width, int height) = 0;
};

// 抽象クラスを用いて四角形を描画するクラス
class Box : public Shape {
public:
	void Draw(int x, int y, int width, int height) override {
		std::cout << "四角形を描画する" << std::endl;
	}
};



int main()
{
	S<int, char, double> t;
	std::cout << t.count << std::endl;

	// Box* b = new Shape();
	Box* b = new Box();
	b->Draw(0, 0, 1, 1);

	return 0;
}