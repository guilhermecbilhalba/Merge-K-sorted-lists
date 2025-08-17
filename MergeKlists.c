#include <stdio.h>
#include <stdlib.h>

struct listNode_t {
    int val;
    struct listNode_t *next;
};

struct listNode_t* CriaLista( int val ) {
    struct listNode_t* new = malloc( sizeof( struct listNode_t ) );
    new->val = val;
    new->next = NULL;
    return new;
}

void AddLista( struct listNode_t* root, int val ) {
    struct listNode_t* cur = root;
    while ( cur->next != NULL ) {
        cur = cur->next;
    }
    cur->next = CriaLista( val );
}

struct listNode_t* UnifyList( struct listNode_t* l1, struct listNode_t* l2 ) {
    if ( !l1 ) {
        return l2;
    }
    if ( !l2 ) {
        return l1;
    }
    struct listNode_t dummy;
    struct listNode_t* tail = &dummy;
    dummy.next = NULL;
    while ( l1 && l2 ) {
        if ( l1->val < l2->val ) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if ( l1 )
    tail->next = l1;
else
    tail->next = l2;

    return dummy.next;
}

struct listNode_t* MergeKLists( struct listNode_t** lists, int listsSize ) {
    if ( listsSize == 0 ) {
        return NULL;
    }
    while ( listsSize > 1 ) {
        int i = 0;
        int j = 0;
        while ( i < listsSize ) {
            if ( i + 1 < listsSize ) {
                lists[j++] = UnifyList( lists[i], lists[i + 1] );
            } else {
                lists[j++] = lists[i];
            }
            i += 2;
        }
        listsSize = j;
    }
    return lists[0];
}

void PrintLista( struct listNode_t* root ) {
    while ( root != NULL ) {
        printf( "%d ", root->val );
        root = root->next;
    }
    printf( "\n" );
}

void FreeLista( struct listNode_t* root ) {
    while ( root != NULL ) {
        struct listNode_t* tmp = root;
        root = root->next;
        free( tmp );
    }
}

int main( void ) {
    struct listNode_t* l1 = CriaLista( 1 );
    AddLista( l1, 4 );
    AddLista( l1, 5 );

    struct listNode_t* l2 = CriaLista( 1 );
    AddLista( l2, 3 );
    AddLista( l2, 4 );

    struct listNode_t* l3 = CriaLista( 2 );
    AddLista( l3, 6 );

    struct listNode_t* lists[3] = { l1, l2, l3 };
    struct listNode_t* result = MergeKLists( lists, 3 );

    PrintLista( result );
    FreeLista( result );
    return 0;
}

