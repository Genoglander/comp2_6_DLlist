#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}

void push_front(list* l, node* p)
{
	if (!l || !p) return;

	p->pPrev = NULL;
	p->pNext = l->header;

	if (l->header)
	{
		l->header->pPrev = p;
	}
	else
	{
		l->footer = p;
	}

	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (!l || !p) return;

	p->pNext = NULL;
	p->pPrev = l->footer;

	if (l->footer)
	{
		l->footer->pNext = p;
	}
	else
	{
		l->header = p;
	}

	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (!l || !p) return;

	if (p->pPrev)
	{
		p->pPrev->pNext = p->pNext;
	}
	else
	{
		l->header = p->pNext;
	}

	if (p->pNext)
	{
		p->pNext->pPrev = p->pPrev;
	}
	else
	{
		l->footer = p->pPrev;
	}

	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (!l || !p) return;

	node* target = p->pNext;
	if (!target) return;

	p->pNext = target->pNext;

	if (target->pNext)
	{
		target->pNext->pPrev = p;
	}
	else
	{
		l->footer = p;
	}

	target->pNext = NULL;
	target->pPrev = NULL;
	// pの前のノードを削除
}

void remove_prev(list* l, node* p)
{
	if (!l || !p) return;

	node* target = p->pPrev;
	if (!target) return;

	p->pPrev = target->pPrev;

	if (target->pPrev)
	{
		target->pPrev->pNext = p;
	}
	else
	{
		l->header = p;
	}

	target->pNext = NULL;
	target->pPrev = NULL;
}

// pの次のノードを取得
node* get_next(list* l, node* p)
{
	(void)l;
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	(void)l;
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
