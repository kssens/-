#include <iostream>
#include <string>
using namespace std;

#define max 1000  //通讯录最多容纳1000人

//联系人结构体
struct Person {
	string name; //姓名
	int sex;//性别
	int age;//年龄
	string number;//电话
	string addr;//家庭住址
};

//通讯录结构体
struct Addressbooks {
	struct Person PersonArray[max];
	int size;//通信录中已记录的联系人个数
};

//显示菜单
void ShowMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl; 
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


//添加联系人
void addPerson(Addressbooks *pabs) {
	if (pabs->size > max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string name;
		int sex = 0;
		int age = 0;
		string phone;
		string address;

		//姓名
		cout << "姓名：" << endl;
		cin >> name;
		pabs->PersonArray[pabs->size].name = name;

		//性别

		cout << "性别" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				pabs->PersonArray[pabs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		cin >> age;
		pabs->PersonArray[pabs->size].age = age;
		
		//电话
		cout << "输入电话：" << endl;
		cin >> phone;
		pabs->PersonArray[pabs->size].number = phone;

		//住址
		cout << "请输入住址" << endl;
		cin >> address;
		pabs->PersonArray[pabs->size].addr = address;
		pabs->size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}

//显示联系人
void ShowPerson(Addressbooks *pabs) {
	//判断人数是否为0
	if (pabs->size == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < pabs->size; i++) {
			cout << "姓名： " << pabs->PersonArray[i].name << "\t";
			cout << "性别： " << (pabs->PersonArray[i].sex==1?"男":"女")<< "\t";//使用三目运算符来输出男女
			cout << "年龄： " << pabs->PersonArray[i].age << "\t";
			cout << "电话： " << pabs->PersonArray[i].number << "\t";
			cout << "住址： " << pabs->PersonArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");

}
//根据姓名来判断是否存在
int IsExist(Addressbooks* pabs,string name) {
	
	for (int i = 0; i < pabs->size;i++) {
		if (pabs->PersonArray[i].name == name) {
			return i;
		}
	}
	return -1;
}
//删除联系人
void DeletePerson(Addressbooks* pabs) {
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret=IsExist(pabs, name);
	if (ret == -1) {
		cout << "未找到此人" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = ret; i < pabs->size; i++) {
			pabs->PersonArray[i] = pabs->PersonArray[i + 1];
		}
		pabs->size--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");

	}
}

//查找联系人

void FindPerson(Addressbooks *pabs) {
	cout << "请输入你要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = IsExist(pabs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "姓名： " << pabs->PersonArray[ret].name << "\t";
		cout << "性别： " << (pabs->PersonArray[ret].sex == 1 ? "男" : "女") << "\t";//使用三目运算符来输出男女
		cout << "年龄： " << pabs->PersonArray[ret].age << "\t";
		cout << "电话： " << pabs->PersonArray[ret].number << "\t";
		cout << "住址： " << pabs->PersonArray[ret].addr << endl;
		system("pause");
		system("cls");
	}
}


//修改联系人信息
void ModifyPerson(Addressbooks* pabs) {
	cout << "请输入你要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = IsExist(pabs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
		cout<<("pause");
		cout<<("cls");
	}
	else {
		//重新输入姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		 pabs->PersonArray[ret].name = name;

		 //重新输入性别
		 int sex;
		 cout << "请输入性别：" << endl;
		 cout << "1-----男" << endl;
		 cout << "2-----女" << endl;
		 while (true) {
			 cin >> sex;
			 if (sex == 1 || sex == 2) {
				 pabs->PersonArray[ret].sex = sex;
				 break;
			 }
			 else {
				 cout << "输入有误，请重新输入：" << endl;
			 }
		 }

		 //重新输入年龄
		 int age;
		 cout << "请输入年龄：" << endl;
		 cin >> age;
		 pabs->PersonArray[ret].age = age;

		 //重新输入电话
		 int number;
			 cout << "请输入电话：" << endl;
			 cin >> number;
			 pabs->PersonArray[ret].number = number;

		 //重新输入地址
			 string addr;
			 cout << "请输入住址：" << endl;
			 cin >> addr;
			 pabs->PersonArray[ret].addr = addr;
	}
	cout << "修改成功" << endl;

}

//清空通讯录
void CleanPerson(Addressbooks* pabs) {
	pabs->size = 0;//逻辑上清空通讯录
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}


int main() {

	Addressbooks abs;
	abs.size = 0;//通讯录初始化

	int select;
	
	while (true) {
		//调用菜单
		ShowMenu();
		cout << "请输入你的选择：" << endl;
		cin >> select;
		switch (select) {
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			ShowPerson(&abs);
			break;
		case 3://删除联系人
		//{ctrl +k+c 直接多行注释
		//	//cout << "请输入你需要删除的联系人：" << endl;
		//	string name;
		//	cin >> name;
		//	if (IsExist(&abs, name) == -1) {
		//		cout << "此人不存在" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		DeletePerson(&abs);
			break;
		//}
		case 4://查找联系人
			FindPerson(&abs);
			break;
		case 5://修改联系人
			ModifyPerson(&abs);
			break;
		case 6://清空联系人
			CleanPerson(&abs);
			break;


		}


	}
	system("pause");
	return 0;
}