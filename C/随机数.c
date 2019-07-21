//int *generateRandomArray(int n, int rangeL, int rangeR) {
//	
//	assert(rangeL <= rangeR); //断言 
//	
//	int *arr[n];
//	int i;
//	//srand（无符号整型）函数,生成随机数种子，rand函数要根据此种子再生成随机数
//	srand(time(NULL));
//	for(i = 0 ; i < n ; i++)
//		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
//	return arr;	
//}
//
