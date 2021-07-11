#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include<vector>

using namespace std;

struct Node  //노드 구조체
{
	int vertex, visit, weight; //(순서대로) 정점, 방문할 노드, 가중치 
};


struct Graph
{
	int V; // 정점의 갯수
	int line; //간선의 갯수

	struct  Node* node; //노드 구조체 포함
};

struct Graph* distanceGraph(int V, int line)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); //graph 구조체에 할당

	graph->V = V; //정점의 갯수 V를 graph의 V로 지정
	graph->line = line; //간선의 갯수 line을 graph의 line으로 지정
	graph->node = (struct  Node*) malloc(graph->line * sizeof(struct  Node)); //그래프 구조체 안에 노드 구조체에서 노드의 수 일정

	return graph; //반환
}

void ShortDist(int Distance[], int n) //최단경로 함수
{
	cout << "<vertex의 최단경로>" << endl;
	int i;

	for (i = 0; i < n; ++i) {
		cout << "dist[" << i << "]:  " << Distance[i] << endl; //최단 경로 Distance[i] 출력
		
	}
}

void BellmanFord(struct Graph* graph, int vertex) //벨만포드 함수
{

	int V = graph->V; //graph의 V로 지정

	int line = graph->line; //graph line으로 지정

	int *Distance;
	Distance = (int *)malloc(V * sizeof(int)); //Distance[V] 선언
											   //그냥 int Distance[V];로 선언할 시 상수가 없다고 에러 뜸

	int i, j;

	for (i = 0; i < V; i++)  //i가 노드의 갯수만큼 증가할 때
		Distance[i] = INT_MAX; //거리 값 무한대로 지정


	Distance[vertex] = 0; //노드(정점) 시작점 0으로 설정

	for (i = 1; i <= V - 1; i++) //i가 V-1만큼 증가 할 때
	{
		for (j = 0; j < line; j++) //j가 간선의 갯수만큼 도달할 때
		{
			int w = graph->node[j].vertex; //시작점이 무한대가 아닐 때
			int v = graph->node[j].visit; //다음 노드로 방문
			int weight = graph->node[j].weight;

			if (Distance[w] + weight < Distance[v]) //시작점부터 최단거리에 가중치를 더한 값이
				Distance[v] = Distance[w] + weight;  //도착노드의 가중치보다 작을 때 바뀜
		}
	}

	//음의 가중치로 경로가 무한히 작아지는 경우
	for (i = 0; i < line; i++) //간선의 갯수만큼 증가
	{
		int w = graph->node[i].vertex; //시작점이 무한대가 아닐 때
		int v = graph->node[i].visit; //다음 노드로 방문
		int weight = graph->node[i].weight;

		
		if (Distance[w] + weight < Distance[v]) //현재 노드에서의 최단거리와 가중치의 합이 계속 작아질 경우
			cout << "음의 싸이클"<<endl; //음의 싸이클 출력
	}

	ShortDist(Distance, V); //최단 경로 함수

	return;
}

int main() //메인함수
{
	int V, line, F;  //(순서대로) 노드의 갯수, 간선의 갯수, 시작점

	cout << "노드(정점)의 갯수: ";
	cin >> V; //노드 갯수 입력

	cout << "간선의 갯수: ";
	cin >> line; //간선 갯수 입력

	cout << "제일 처음 시작하는 노드: ";
	cin >> F; //처음 시작 노드 입력
	cout << endl;

	struct Graph* graph = distanceGraph(V, line);   //함수 공간 할당

	int i;

	cout << "시작점, 도착점, 가중점 차례대로 나타내기" << endl;
	for (i = 0; i<line; i++) { //i가 간선의 갯수만큼 증가할 때
		cin >> graph->node[i].vertex; //시작점
		cin >> graph->node[i].visit; //도착점
		cin >> graph->node[i].weight; //가중점
	}

	cout << endl;

	BellmanFord(graph, F); ////생성된 그래프와 노드를 벨만포드 함수에 입력

	return 0;
}