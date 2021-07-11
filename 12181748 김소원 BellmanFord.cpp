#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include<vector>

using namespace std;

struct Node  //��� ����ü
{
	int vertex, visit, weight; //(�������) ����, �湮�� ���, ����ġ 
};


struct Graph
{
	int V; // ������ ����
	int line; //������ ����

	struct  Node* node; //��� ����ü ����
};

struct Graph* distanceGraph(int V, int line)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); //graph ����ü�� �Ҵ�

	graph->V = V; //������ ���� V�� graph�� V�� ����
	graph->line = line; //������ ���� line�� graph�� line���� ����
	graph->node = (struct  Node*) malloc(graph->line * sizeof(struct  Node)); //�׷��� ����ü �ȿ� ��� ����ü���� ����� �� ����

	return graph; //��ȯ
}

void ShortDist(int Distance[], int n) //�ִܰ�� �Լ�
{
	cout << "<vertex�� �ִܰ��>" << endl;
	int i;

	for (i = 0; i < n; ++i) {
		cout << "dist[" << i << "]:  " << Distance[i] << endl; //�ִ� ��� Distance[i] ���
		
	}
}

void BellmanFord(struct Graph* graph, int vertex) //�������� �Լ�
{

	int V = graph->V; //graph�� V�� ����

	int line = graph->line; //graph line���� ����

	int *Distance;
	Distance = (int *)malloc(V * sizeof(int)); //Distance[V] ����
											   //�׳� int Distance[V];�� ������ �� ����� ���ٰ� ���� ��

	int i, j;

	for (i = 0; i < V; i++)  //i�� ����� ������ŭ ������ ��
		Distance[i] = INT_MAX; //�Ÿ� �� ���Ѵ�� ����


	Distance[vertex] = 0; //���(����) ������ 0���� ����

	for (i = 1; i <= V - 1; i++) //i�� V-1��ŭ ���� �� ��
	{
		for (j = 0; j < line; j++) //j�� ������ ������ŭ ������ ��
		{
			int w = graph->node[j].vertex; //�������� ���Ѵ밡 �ƴ� ��
			int v = graph->node[j].visit; //���� ���� �湮
			int weight = graph->node[j].weight;

			if (Distance[w] + weight < Distance[v]) //���������� �ִܰŸ��� ����ġ�� ���� ����
				Distance[v] = Distance[w] + weight;  //��������� ����ġ���� ���� �� �ٲ�
		}
	}

	//���� ����ġ�� ��ΰ� ������ �۾����� ���
	for (i = 0; i < line; i++) //������ ������ŭ ����
	{
		int w = graph->node[i].vertex; //�������� ���Ѵ밡 �ƴ� ��
		int v = graph->node[i].visit; //���� ���� �湮
		int weight = graph->node[i].weight;

		
		if (Distance[w] + weight < Distance[v]) //���� ��忡���� �ִܰŸ��� ����ġ�� ���� ��� �۾��� ���
			cout << "���� ����Ŭ"<<endl; //���� ����Ŭ ���
	}

	ShortDist(Distance, V); //�ִ� ��� �Լ�

	return;
}

int main() //�����Լ�
{
	int V, line, F;  //(�������) ����� ����, ������ ����, ������

	cout << "���(����)�� ����: ";
	cin >> V; //��� ���� �Է�

	cout << "������ ����: ";
	cin >> line; //���� ���� �Է�

	cout << "���� ó�� �����ϴ� ���: ";
	cin >> F; //ó�� ���� ��� �Է�
	cout << endl;

	struct Graph* graph = distanceGraph(V, line);   //�Լ� ���� �Ҵ�

	int i;

	cout << "������, ������, ������ ���ʴ�� ��Ÿ����" << endl;
	for (i = 0; i<line; i++) { //i�� ������ ������ŭ ������ ��
		cin >> graph->node[i].vertex; //������
		cin >> graph->node[i].visit; //������
		cin >> graph->node[i].weight; //������
	}

	cout << endl;

	BellmanFord(graph, F); ////������ �׷����� ��带 �������� �Լ��� �Է�

	return 0;
}