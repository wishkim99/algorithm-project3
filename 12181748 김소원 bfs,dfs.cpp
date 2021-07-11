#include <iostream>
#include <queue> //큐 사용
#include <cstring>

#define MAX 101 //임의로 설정

using namespace std;

int graph[MAX][MAX]; //그래프
int visit[MAX]; //노드 갯수만큼 방문
queue<int> q;
int node, line, f; //각각 노드, 간선, 시작점


void Bfs(int f) { //BFS 함수
	visit[f] = 1; //노드를 방문하면
	q.push(f); //push해줌

	while (!q.empty()) {
		f = q.front(); // 처음 노드
		q.pop(); //pop해줌

		cout << f << " "; //bfs는 pop으로 이동
		for (int i = 1; i <= node; i++) { //방문하지 않은 연결된 노드 찾기
			if (graph[f][i] && !visit[i]) { //노드 f와 i가 만나고,노드 i는 방문하지 않음
				q.push(i); //노드 방문했으면 push
				visit[i] = 1; //큐에 넣음
			}
		}
	}
}

void Dfs(int f) { //DFS 함수
	cout << f << " ";
	visit[f] = 1; //노드를 방문함
	for (int i = 1; i <= node; i++) { //i가 노드의 갯수만큼 증가할 때
		if (graph[f][i] && !visit[i]) { //노드 방문했으면
			Dfs(i); //Dfs 
		}
	}
}

int main(void) {
	
	cout << "노드 갯수: ";
	cin >> node;
	
	cout << "간선 갯수: ";
	cin >> line;
	
	cout << "시작 노드(정점): ";
	cin >> f;
	cout << endl;

	memset (graph, 0, sizeof(graph)); //memset 함수로 graph 값 모두 지정
	memset(visit, 0, sizeof(visit)); //visit 값 모두 지정

	cout << "연결된 두 노드들(간선) " << endl;
	for (int i = 0; i < line; i++) {
		int a, b; //간선을 연결
		cout << "=>";
		cin >> a >> b;

		graph[a][b] = 1; //두 노드가 연결되어있음
		graph[b][a] = 1; //두 노드 연결
	}

	cout << endl;
	cout << "BFS 결과: ";
	Bfs(f); //Bfs 함수
	cout << "\n" << endl;

	memset(visit, 0, sizeof(visit)); //visit 값 모두 지정

	cout << "DFS 결과: ";
	Dfs(f); //Dfs 함수
	cout << "\n" << endl;
	return 0;
}
