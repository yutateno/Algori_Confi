#include <iostream>

using namespace std;

// 関数ポインタ
int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b) 
{
	return a * b;
}


// メンバ関数ポインタ
class Function
{
public:
	int diff(int a, int b)
	{
		return a - b;
	}


	int mul(int a, int b)
	{
		return a * b;
	}


	int calc(int index)
	{
		int (Function::*class_funcs[2])(int a, int b) = { &Function::diff, &Function::mul };
		return (this->*class_funcs[index])(300, 30);
	}
};



// 継承メンバ関数ポインタ
class CBase;
typedef void (CBase::*FUNC)(void);

class CBase
{
private:
	static const int m_nNumFunc;
	static FUNC apfnTable[];
public:
	virtual int GetNumFunc(void) { return m_nNumFunc; }
	virtual FUNC GetFunc(int nIndex) { return apfnTable[nIndex]; }
	virtual void ExecFunc(int nIndex) { (this->*apfnTable[nIndex])(); }
	virtual void Test0(void) { cout << "BT0" << endl; }
	virtual void Test1(void) { cout << "BT1" << endl; }
	virtual void Test2(void) { cout << "BT2" << endl; }
};


void (CBase::*CBase::apfnTable[])(void) = { &CBase::Test0, &CBase::Test1, &CBase::Test2, };
// FUNC CBase::apfnTable[] = { &CBase::Test0, &CBase::Test1, &CBase::Test2, };

const int CBase::m_nNumFunc = sizeof(CBase::apfnTable) / sizeof(CBase::apfnTable[0]);

class CDerived0 : public CBase 
{
public:
	int GetNumFunc(void) { return 2; }
	void Test0(void) { cout << "D0T0" << endl; }
	void Test1(void) { cout << "D0T1" << endl; }
};

class CDerived1 : public CBase 
{
public:
	int GetNumFunc(void) { return 3; }
	void Test0(void) { cout << "D1T0" << endl; }
	void Test1(void) { cout << "D1T1" << endl; }
	void Test2(void) { cout << "D1T2" << endl; }
};


int main(int argc, char const *argv[])
{
	int(*func[])(int a, int b) = { add,mul };


	// 関数ポインタ
	cout << (*func[0])(10, 20) << endl;
	cout << (*func[1])(10, 20) << endl;


	Function fc;
	Function* p_fc = new Function();
	// メンバ関数ポインタ
	int (Function::*class_func)(int a, int b) = &Function::diff;
	cout << (fc.*class_func)(10, 20) << endl;
	cout << (p_fc->*class_func)(20, 40) << endl;
	delete p_fc;


	// メンバ関数ポインタ配列
	int (Function::*class_funcs[2])(int a, int b) = { &Function::diff, &Function::mul };
	cout << (fc.*class_funcs[0])(10, 20) << endl;
	cout << (fc.*class_funcs[1])(300, 20) << endl;

	cout << fc.calc(0) << endl;
	cout << fc.calc(1) << endl;


	// 継承関数ポインタ
	CBase *pBase0 = new CDerived0;
	CBase *pBase1 = new CDerived1;

	for (int i = 0; i < pBase0->GetNumFunc(); i++) pBase0->ExecFunc(i);
	for (int i = 0; i < pBase1->GetNumFunc(); i++) pBase1->ExecFunc(i);

	for (int i = 0; i < pBase0->GetNumFunc(); i++)
	{
		FUNC pfn = pBase0->GetFunc(i);
		(pBase0->*pfn)();
	}

	for (int i = 0; i < pBase1->GetNumFunc(); i++)
	{
		FUNC pfn = pBase1->GetFunc(i);
		(pBase1->*pfn)();
	}

	delete pBase0;
	delete pBase1;

	return 0;
}