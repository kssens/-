#include <iostream>
#include <string>
using namespace std;

#define max 1000  //ͨѶ¼�������1000��

//��ϵ�˽ṹ��
struct Person {
	string name; //����
	int sex;//�Ա�
	int age;//����
	string number;//�绰
	string addr;//��ͥסַ
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person PersonArray[max];
	int size;//ͨ��¼���Ѽ�¼����ϵ�˸���
};

//��ʾ�˵�
void ShowMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl; 
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


//�����ϵ��
void addPerson(Addressbooks *pabs) {
	if (pabs->size > max) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name;
		int sex = 0;
		int age = 0;
		string phone;
		string address;

		//����
		cout << "������" << endl;
		cin >> name;
		pabs->PersonArray[pabs->size].name = name;

		//�Ա�

		cout << "�Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				pabs->PersonArray[pabs->size].sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		cin >> age;
		pabs->PersonArray[pabs->size].age = age;
		
		//�绰
		cout << "����绰��" << endl;
		cin >> phone;
		pabs->PersonArray[pabs->size].number = phone;

		//סַ
		cout << "������סַ" << endl;
		cin >> address;
		pabs->PersonArray[pabs->size].addr = address;
		pabs->size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//����
	}
}

//��ʾ��ϵ��
void ShowPerson(Addressbooks *pabs) {
	//�ж������Ƿ�Ϊ0
	if (pabs->size == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < pabs->size; i++) {
			cout << "������ " << pabs->PersonArray[i].name << "\t";
			cout << "�Ա� " << (pabs->PersonArray[i].sex==1?"��":"Ů")<< "\t";//ʹ����Ŀ������������Ů
			cout << "���䣺 " << pabs->PersonArray[i].age << "\t";
			cout << "�绰�� " << pabs->PersonArray[i].number << "\t";
			cout << "סַ�� " << pabs->PersonArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");

}
//�����������ж��Ƿ����
int IsExist(Addressbooks* pabs,string name) {
	
	for (int i = 0; i < pabs->size;i++) {
		if (pabs->PersonArray[i].name == name) {
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void DeletePerson(Addressbooks* pabs) {
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret=IsExist(pabs, name);
	if (ret == -1) {
		cout << "δ�ҵ�����" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = ret; i < pabs->size; i++) {
			pabs->PersonArray[i] = pabs->PersonArray[i + 1];
		}
		pabs->size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");

	}
}

//������ϵ��

void FindPerson(Addressbooks *pabs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = IsExist(pabs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������ " << pabs->PersonArray[ret].name << "\t";
		cout << "�Ա� " << (pabs->PersonArray[ret].sex == 1 ? "��" : "Ů") << "\t";//ʹ����Ŀ������������Ů
		cout << "���䣺 " << pabs->PersonArray[ret].age << "\t";
		cout << "�绰�� " << pabs->PersonArray[ret].number << "\t";
		cout << "סַ�� " << pabs->PersonArray[ret].addr << endl;
		system("pause");
		system("cls");
	}
}


//�޸���ϵ����Ϣ
void ModifyPerson(Addressbooks* pabs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = IsExist(pabs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
		cout<<("pause");
		cout<<("cls");
	}
	else {
		//������������
		string name;
		cout << "������������" << endl;
		cin >> name;
		 pabs->PersonArray[ret].name = name;

		 //���������Ա�
		 int sex;
		 cout << "�������Ա�" << endl;
		 cout << "1-----��" << endl;
		 cout << "2-----Ů" << endl;
		 while (true) {
			 cin >> sex;
			 if (sex == 1 || sex == 2) {
				 pabs->PersonArray[ret].sex = sex;
				 break;
			 }
			 else {
				 cout << "�����������������룺" << endl;
			 }
		 }

		 //������������
		 int age;
		 cout << "���������䣺" << endl;
		 cin >> age;
		 pabs->PersonArray[ret].age = age;

		 //��������绰
		 int number;
			 cout << "������绰��" << endl;
			 cin >> number;
			 pabs->PersonArray[ret].number = number;

		 //���������ַ
			 string addr;
			 cout << "������סַ��" << endl;
			 cin >> addr;
			 pabs->PersonArray[ret].addr = addr;
	}
	cout << "�޸ĳɹ�" << endl;

}

//���ͨѶ¼
void CleanPerson(Addressbooks* pabs) {
	pabs->size = 0;//�߼������ͨѶ¼
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


int main() {

	Addressbooks abs;
	abs.size = 0;//ͨѶ¼��ʼ��

	int select;
	
	while (true) {
		//���ò˵�
		ShowMenu();
		cout << "���������ѡ��" << endl;
		cin >> select;
		switch (select) {
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3://ɾ����ϵ��
		//{ctrl +k+c ֱ�Ӷ���ע��
		//	//cout << "����������Ҫɾ������ϵ�ˣ�" << endl;
		//	string name;
		//	cin >> name;
		//	if (IsExist(&abs, name) == -1) {
		//		cout << "���˲�����" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
		DeletePerson(&abs);
			break;
		//}
		case 4://������ϵ��
			FindPerson(&abs);
			break;
		case 5://�޸���ϵ��
			ModifyPerson(&abs);
			break;
		case 6://�����ϵ��
			CleanPerson(&abs);
			break;


		}


	}
	system("pause");
	return 0;
}