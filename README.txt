1) AVL tree를 만드는 프로그램을 완성하시오. 

① Program 10.2(textbook pp. 502)와 Program 10.3(extbook pp. 503)의 동작을 확인하시오. (LL rotation and LR rotation)

	%cat input.txt
	 6   				// n = 6
	20   10   30   5    3    8	

%cat output.txt
CBT 1번 노드 = 10	bf = 0
CBT 2번 노드 = 5	bf = 0
CBT 3번 노드 = 20	bf = -1
CBT 4번 노드 = 3	bf = 0
CBT 5번 노드 = 8	bf = 0
CBT 7번 노드 = 30	bf = 0

② 위의 프로그램을 확장하여 right rotation(RR rotation and RL rotation)을 지원하는 함수를 완성하시오. 

	%cat input.txt
	 10   							// n = 10
	20   10   30   5    3    8    40    6    9     7	

%cat output.txt
CBT 1번 노드 = 10	bf = 1
CBT 2번 노드 = 6	bf = 0
CBT 3번 노드 = 30	bf = 0
CBT 4번 노드 = 5	bf = 1
CBT 5번 노드 = 8	bf = 0
CBT 6번 노드 = 20	bf = 0
CBT 7번 노드 = 40	bf = 0
CBT 8번 노드 = 3	bf = 0
CBT 10번 노드 = 7	bf = 0
CBT 11번 노드 = 9	bf = 0
