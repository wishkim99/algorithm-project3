#include <iostream>
#include <queue> //ť ���
#include <cstring>

#define MAX 101 //���Ƿ� ����

using namespace std;

int graph[MAX][MAX]; //�׷���
int visit[MAX]; //��� ������ŭ �湮
queue<int> q;
int node, line, f; //���� ���, ����, ������


void Bfs(int f) { //BFS �Լ�
	visit[f] = 1; //��带 �湮�ϸ�
	q.push(f); //push����

	while (!q.empty()) {
		f = q.front(); // ó�� ���
		q.pop(); //pop����

		cout << f << " "; //bfs�� pop���� �̵�
		for (int i = 1; i <= node; i++) { //�湮���� ���� ����� ��� ã��
			if (graph[f][i] && !visit[i]) { //��� f�� i�� ������,��� i�� �湮���� ����
				q.push(i); //��� �湮������ push
				visit[i] = 1; //ť�� ����
			}
		}
	}
}

void Dfs(int f) { //DFS �Լ�
	cout << f << " ";
	visit[f] = 1; //��带 �湮��
	for (int i = 1; i <= node; i++) { //i�� ����� ������ŭ ������ ��
		if (graph[f][i] && !visit[i]) { //��� �湮������
			Dfs(i); //Dfs 
		}
	}
}

int main(void) {
	
	cout << "��� ����: ";
	cin >> node;
	
	cout << "���� ����: ";
	cin >> line;
	
	cout << "���� ���(����): ";
	cin >> f;
	cout << endl;

	memset (graph, 0, sizeof(graph)); //memset �Լ��� graph �� ��� ����
	memset(visit, 0, sizeof(visit)); //visit �� ��� ����

	cout << "����� �� ����(����) " << endl;
	for (int i = 0; i < line; i++) {
		int a, b; //������ ����
		cout << "=>";
		cin >> a >> b;

		graph[a][b] = 1; //�� ��尡 ����Ǿ�����
		graph[b][a] = 1; //�� ��� ����
	}

	cout << endl;
	cout << "BFS ���: ";
	Bfs(f); //Bfs �Լ�
	cout << "\n" << endl;

	memset(visit, 0, sizeof(visit)); //visit �� ��� ����

	cout << "DFS ���: ";
	Dfs(f); //Dfs �Լ�
	cout << "\n" << endl;
	return 0;
}
