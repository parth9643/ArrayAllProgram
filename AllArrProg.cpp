#include <iostream>
using namespace std;
struct array
{
    int *A;
    int length;
    int size;
};
void display(struct array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d \n", arr.A[i]);
    }
}
void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }

    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int RecBinSearch(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RecBinSearch(a, l, mid - 1, key);
        else
            return RecBinSearch(a, mid + 1, h, key);
    }
    return -1;
}
int Get(struct array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void Set(struct array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}
int Max(struct array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int Min(struct array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int Sum(struct array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];

    return s;
}
float Avg(struct array arr)
{
    return (float)Sum(arr) / arr.length;
}
void Reverse(struct array *arr)
{
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}
void Reverse2(struct array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void InsertSort(struct array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
int isSorted(struct array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
void Rearrange(struct array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
struct array *Merge(struct array *arr1, struct array
                                            *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}
struct array *Union(struct array *arr1, struct array
                                            *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
struct array *Intersection(struct array *arr1, struct
                           array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
struct array *Difference(struct array *arr1, struct
                         array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct array arr1;
    struct array arr2;
    int ch;
    int x, index, y;

    printf("Enter Size of Array 1");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    printf("Enter Size of Array 2");
    scanf("%d", &arr2.size);
    arr2.A = (int *)malloc(arr2.size * sizeof(int));
    arr2.length = 0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Append \n");
        printf("6. Swap\n");
        printf("7. Binary Search\n");
        printf("8. Get\n");
        printf("9. Set\n");
        printf("10. Max\n");
        printf("11. Min\n");
        printf("12. Average\n");
        printf("13. Reverse\n");
        printf("14. Insert Sort\n");
        printf("15. Merge of two Sorted Arrays\n");
        printf("16. Unioun of two Sorted Arrays\n");
        printf("17. Intersection of two Sorted Arrays\n");
        printf("18. Diffrence of two Sorted Arrays\n");
        printf("19. Display\n");
        printf("20. Exit \n");
        printf("enter you choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index %d", index);
            break;
        case 4:
            printf("Sum is %d\n", Sum(arr1));
            break;
        case 5:
            printf("Enter an element to append");
            scanf("%d", &x);
            append(&arr1, x);
            break;
        case 6:
            printf("Enter element 1 and element 2");
            scanf("%d%d", &x, &y);
            swap(&x, &y);
            break;
        case 7:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = BinarySearch(arr1, x);
            printf("Element index %d", index);
            break;
        case 8:
            printf("Enter index no");
            scanf("%d", &index);
            Get(arr1, index);
            break;
        case 9:
            printf("Enter an element, index and value");
            scanf("%d%d", &index, &x);
            Set(&arr1, index, x);
            break;
        case 10:
            printf("The max element is ");
            Max(arr1);
            break;
        case 11:
            printf("The min element is ");
            Min(arr1);
            break;
        case 12:
            printf("The average of element is ");
            Avg(arr1);
            break;
        case 13:
            printf("The Reversed Array is ");
            Reverse2(&arr1);
            break;
        case 14:
            printf("Sorted Array:");
            scanf("%d", &x);
            InsertSort(&arr1, x);
            break;
        case 15:
            printf("The Merged Array :");
            if (isSorted(arr1) && isSorted(arr2))
            {
                Merge(&arr1, &arr2);
            }
            else
            {
                printf("Enter the sorted Arrays");
            }
            break;

        case 16:
            printf("The Union of two Array :");
            if (isSorted(arr1) && isSorted(arr2))
            {
                Union(&arr1, &arr2);
            }
            else
            {
                printf("Enter the sorted Arrays");
            }
            break;
        case 17:
            printf("The Intersection of two Arrays :");
            if (isSorted(arr1) && isSorted(arr2))
            {
                Intersection(&arr1, &arr2);
            }
            else
            {
                printf("Enter the sorted Arrays");
            }
            break;
        case 18:
            printf("The Diffrence of two Arrays :");
            if (isSorted(arr1) && isSorted(arr2))
            {
                Difference(&arr1, &arr2);
            }
            else
            {
                printf("Enter the sorted Arrays");
            }
            break;

        case 19:
            display(arr1);
        }

    } while (ch < 20);
    return 0;
}
