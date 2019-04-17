#include"SeqList .h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	psl->capicity = capacity;
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->size = 0;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	SLDataType* ptr;
	if (psl->size == psl->capicity)
	{
		psl->capicity = psl->capicity * 2;
		ptr = realloc(psl->array, sizeof(SLDataType)*psl->capicity);
		if (ptr != NULL)
		{
			psl->array = ptr;
		}
		else
		{
			printf("增容失败\n");
			return;
		}
		printf("增容成功\n");
	}

}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	if (pos > psl->size)
	{
		printf("输入地址错误\n");
		return;
	}
	else
	{
		for (i = psl->size; i > pos; i--)
		{
			psl->array[i] = psl->array[i - 1];
		}
		psl->array[i] = x;
		psl->size++;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, psl->size, x);
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, 0, x);
}

void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl,psl->size-1);
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl, 0);
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	printf("没找到\n");
	return -1;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListErase(psl, SeqListFind(psl, x));
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	psl->array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	
}
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	int i, j;
	SLDataType x;
	for (i = 0; i < psl->size-1; i++)
	{
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				x = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = x;
			}
		}
	}
}




int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left;
	int right;
	int mid;
	left = 0;
	right = psl->size;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (x>psl->array[mid])
		{
			left = mid + 1;
		}
		else if (x<psl->array[mid])
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	printf("没找到\n");
	return -1;
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int i;
	int set;
	SLDataType* p1=psl->array;
	set = psl->size;
	for (i = 0; i < set; i++)
	{
		if (psl->array[i] != x)
		{
			*p1 = psl->array[i];
			p1++;
		}
		else
		{
			psl->size--;
		}

	}
}
void test()
{
	SeqList t;
	SeqListInit(&t, 10);


	SeqListPushBack(&t, 4);

	SeqListPushBack(&t, 1);
	SeqListPushBack(&t, 2);	
	SeqListPushBack(&t, 4);
	SeqListPushBack(&t, 4);
	SeqListPushBack(&t, 3);
	SeqListPushBack(&t, 4);
	SeqListPushFront(&t, 0);
	SeqListPushBack(&t, 4);
	SeqListBubbleSort(&t);


	SeqListPrint(&t);
}