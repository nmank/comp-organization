/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "dreamteam",              /* Team name */

    "Nate Mankovich",     /* First member full name */
    "nathan.mankovich@coloradocollege.edu",  /* First member email address */

    "Tom Hanks",                   /* Second member full name (leave blank if none) */
    "forest-guuuuump@yolo.org"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate1 - 4 blocks loop swap
 */
char rotate1_descr[] = "4 blocks";
void rotate1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < (dim/2); i++)
    for (j = 0; j < (dim/2); j++)
        dst[RIDX(dim-1-i, j, dim)] = src[RIDX(j, i, dim)];

    for (i = (dim/2); i < dim; i++)
    for (j = 0; j < (dim/2); j++)
        dst[RIDX(dim-1-i, j, dim)] = src[RIDX(j, i, dim)];

    for (i = 0; i < (dim/2); i++)
    for (j = (dim/2); j < dim; j++)
        dst[RIDX(dim-1-i, j, dim)] = src[RIDX(j, i, dim)];

    for (i = (dim/2); i < dim; i++)
    for (j = (dim/2); j < dim; j++)
        dst[RIDX(dim-1-i, j, dim)] = src[RIDX(j, i, dim)];
}

/* 
 * rotate2 - loop swap
 */
char rotate2_descr[] = "rotate2: it might work";
void rotate2(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (j = 0; j < dim; j++)
    for (i = 0; i < dim; i++)
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}


/* 
 * rotate3 - loop swap
 */
 /*
char rotate3_descr[] = "rotate3: loop unrolled";
void rotate3(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    i = 0;

    for (j = 0; j < dim; j++)
    for (i = 0; i < dim; i++)
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        i++;
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}
*/

/*
* rotate_best - block and intex switch
*/
char rotate_descr[] = "rotate- current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{

    int i, j, jj;
    int BLOCK_SIZE = 16;
    int END;
    int BLOCK_SIZE1 = 16;

    for (j = 0; j < dim; j+=BLOCK_SIZE)
    {
        BLOCK_SIZE1 = j + BLOCK_SIZE;
        END = (dim < BLOCK_SIZE1 ? dim : BLOCK_SIZE1);

        for (i = 0; i < dim; i++)
        {
            for ( jj = j; jj < END; jj++ )
            {
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;

                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;

                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;

                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
                jj++;
                dst[RIDX(dim-1-jj, i, dim)] = src[RIDX(i, jj, dim)];
            }
        } 
    }
}

/* 
 * rotate3 - loop swap
 */
char rotate4_descr[] = "rotate4: blocks";
void rotate4(int dim, pixel *src, pixel *dst) 
{
    int i, j, b;
    b = 32;
    for (b = 0; b < dim; b = b + 32) {
        for (j = 0; j < b; j++) {
            for (i = 0; i < b; i++)
                {dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];}  
        }
    }
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
 /*
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    naive_rotate(dim, src, dst);
}
*/

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate1, rotate1_descr);
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
    for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth1_descr[] = "smooth: blabla" ;
void smooth1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    //top row
    for (j = 0; j < dim; j++)
        {
            dst[RIDX(0, j, dim)] = avg(dim, 0, j, src);
        }

    //middle
    int dim1 = dim-1;
    for (i = 1; i < dim1; i++)
    {
        for (j = 0; j < dim; j++)
        {
            dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
        }
    }   

    //bottom row
    for (j = 0; j < dim; j++)
    {
        dst[RIDX(dim1, j, dim)] = avg(dim, dim1, j, src);
    }

    //column 1
    for (i = 1; i < dim1; i++)
    {
        dst[RIDX(i, 0, dim)] = avg(dim, i, 0, src);
    }

    //column last
    for (i = 1; i < dim1; i++)
    {
        dst[RIDX(i, dim1, dim)] = avg(dim, i, dim1, src);
    }
}

/*
 * smooth - function inlining 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    int dim1 = dim-1;

    //corners (j,i):
    //(0,0)
    unsigned short r00 = src[RIDX(0, 0, dim)].red;
    unsigned short g00 = src[RIDX(0, 0, dim)].green;
    unsigned short b00 = src[RIDX(0, 0, dim)].blue;

    unsigned short r01 = src[RIDX(0, 1, dim)].red;
    unsigned short g01 = src[RIDX(0, 1, dim)].green;
    unsigned short b01 = src[RIDX(0, 1, dim)].blue;

    unsigned short r11 = src[RIDX(1, 0, dim)].red;
    unsigned short g11 = src[RIDX(1, 0, dim)].green;
    unsigned short b11 = src[RIDX(1, 0, dim)].blue;

    unsigned short r10 = src[RIDX(1, 1, dim)].red;
    unsigned short g10 = src[RIDX(1, 1, dim)].green;
    unsigned short b10 = src[RIDX(1, 1, dim)].blue;

    pixel current_pixel = src[RIDX(0, 0, dim)];

    current_pixel.red = (r00+r01+r11+r10)/4;
    current_pixel.green = (g00+g01+g11+g10)/4;
    current_pixel.blue = (b00+b01+b11+b10)/4;

    dst[RIDX(0, 0, dim)] = current_pixel;

    //(0,dim1)
    int dim2 = dim1-1;

    r00 = src[RIDX(0, dim1, dim)].red;
    g00 = src[RIDX(0, dim1, dim)].green;
    b00 = src[RIDX(0, dim1, dim)].blue;

    r01 = src[RIDX(0, dim2, dim)].red;
    g01 = src[RIDX(0, dim2, dim)].green;
    b01 = src[RIDX(0, dim2, dim)].blue;

    r11 = src[RIDX(1, dim1, dim)].red;
    g11 = src[RIDX(1, dim1, dim)].green;
    b11 = src[RIDX(1, dim1, dim)].blue;

    r10 = src[RIDX(1, dim2, dim)].red;
    g10 = src[RIDX(1, dim2, dim)].green;
    b10 = src[RIDX(1, dim2, dim)].blue;

    current_pixel = src[RIDX(0, dim1, dim)];

    current_pixel.red = (r00+r01+r11+r10)/4;
    current_pixel.green = (g00+g01+g11+g10)/4;
    current_pixel.blue = (b00+b01+b11+b10)/4;

    dst[RIDX(0, dim1, dim)] = current_pixel;

//(dim1,0)
    r00 = src[RIDX(dim1, 0, dim)].red;
    g00 = src[RIDX(dim1, 0, dim)].green;
    b00 = src[RIDX(dim1, 0, dim)].blue;

    r01 = src[RIDX(dim2, 0, dim)].red;
    g01 = src[RIDX(dim2, 0, dim)].green;
    b01 = src[RIDX(dim2, 0, dim)].blue;

    r11 = src[RIDX(dim1, 1, dim)].red;
    g11 = src[RIDX(dim1, 1, dim)].green;
    b11 = src[RIDX(dim1, 1, dim)].blue;

    r10 = src[RIDX(dim2, 1, dim)].red;
    g10 = src[RIDX(dim2, 1, dim)].green;
    b10 = src[RIDX(dim2, 1, dim)].blue;

    current_pixel = src[RIDX(dim1, 0, dim)];

    current_pixel.red = (r00+r01+r11+r10)/4;
    current_pixel.green = (g00+g01+g11+g10)/4;
    current_pixel.blue = (b00+b01+b11+b10)/4;

    dst[RIDX(dim1, 0, dim)] = current_pixel;

//(dim1,dim1)
    r00 = src[RIDX(dim1, dim1, dim)].red;
    g00 = src[RIDX(dim1, dim1, dim)].green;
    b00 = src[RIDX(dim1, dim1, dim)].blue;

    r01 = src[RIDX(dim2, dim1, dim)].red;
    g01 = src[RIDX(dim2, dim1, dim)].green;
    b01 = src[RIDX(dim2, dim1, dim)].blue;

    r11 = src[RIDX(dim1, dim2, dim)].red;
    g11 = src[RIDX(dim1, dim2, dim)].green;
    b11 = src[RIDX(dim1, dim2, dim)].blue;

    r10 = src[RIDX(dim2, dim2, dim)].red;
    g10 = src[RIDX(dim2, dim2, dim)].green;
    b10 = src[RIDX(dim2, dim2, dim)].blue;

    current_pixel = src[RIDX(dim1, dim1, dim)];

    current_pixel.red = (r00+r01+r11+r10)/4;
    current_pixel.green = (g00+g01+g11+g10)/4;
    current_pixel.blue = (b00+b01+b11+b10)/4;

    dst[RIDX(dim1, dim1, dim)] = current_pixel;




    //top row
    for (j = 1; j < dim1; j++)
        {
            int jm = j-1;
            int jp = j+1;

            unsigned short r00 = src[RIDX(0, j, dim)].red;
            unsigned short g00 = src[RIDX(0, j, dim)].green;
            unsigned short b00 = src[RIDX(0, j, dim)].blue;

            unsigned short r0m1 = src[RIDX(0, jm, dim)].red;
            unsigned short g0m1 = src[RIDX(0, jm, dim)].green;
            unsigned short b0m1 = src[RIDX(0, jm, dim)].blue;

            unsigned short r01 = src[RIDX(0, jp, dim)].red;
            unsigned short g01 = src[RIDX(0, jp, dim)].green;
            unsigned short b01 = src[RIDX(0, jp, dim)].blue;

            unsigned short r11 = src[RIDX(1, j, dim)].red;
            unsigned short g11 = src[RIDX(1, j, dim)].green;
            unsigned short b11 = src[RIDX(1, j, dim)].blue;

            unsigned short r1m1 = src[RIDX(1, jm, dim)].red;
            unsigned short g1m1 = src[RIDX(1, jm, dim)].green;
            unsigned short b1m1 = src[RIDX(1, jm, dim)].blue;

            unsigned short r10 = src[RIDX(1, jp, dim)].red;
            unsigned short g10 = src[RIDX(1, jp, dim)].green;
            unsigned short b10 = src[RIDX(1, jp, dim)].blue;

            pixel current_pixel = src[RIDX(0, j, dim)];

            current_pixel.red = (r00+r0m1+r01+r11+r1m1+r10)/6;
            current_pixel.green = (g00+g0m1+g01+g11+g1m1+g10)/6;
            current_pixel.blue = (b00+b0m1+b01+b11+b1m1+b10)/6;

            dst[RIDX(0, j, dim)] = current_pixel;
        }

    //middle
    for (i = 1; i < dim1; i++)
    {
        for (j = 1; j < dim1; j++)
        {
            int jm = j-1;
            int jp = j+1;

            int im = i-1;
            int ip = i+1;

            unsigned short r00 = src[RIDX(i, j, dim)].red;
            unsigned short g00 = src[RIDX(i, j, dim)].green;
            unsigned short b00 = src[RIDX(i, j, dim)].blue;

            unsigned short r0m1 = src[RIDX(i, jm, dim)].red;
            unsigned short g0m1 = src[RIDX(i, jm, dim)].green;
            unsigned short b0m1 = src[RIDX(i, jm, dim)].blue;

            unsigned short rm10 = src[RIDX(im, j, dim)].red;
            unsigned short gm10 = src[RIDX(im, j, dim)].green;
            unsigned short bm10 = src[RIDX(im, j, dim)].blue;

            unsigned short rm1m1 = src[RIDX(im, jm, dim)].red;
            unsigned short gm1m1 = src[RIDX(im, jm, dim)].green;
            unsigned short bm1m1 = src[RIDX(im, jm, dim)].blue;

            unsigned short r01 = src[RIDX(i, jp, dim)].red;
            unsigned short g01 = src[RIDX(i, jp, dim)].green;
            unsigned short b01 = src[RIDX(i, jp, dim)].blue;

            unsigned short r10 = src[RIDX(ip, j, dim)].red;
            unsigned short g10 = src[RIDX(ip, j, dim)].green;
            unsigned short b10 = src[RIDX(ip, j, dim)].blue;

            unsigned short rm11 = src[RIDX(im, jp, dim)].red;
            unsigned short gm11 = src[RIDX(im, jp, dim)].green;
            unsigned short bm11 = src[RIDX(im, jp, dim)].blue;

            unsigned short r1m1 = src[RIDX(ip, jm, dim)].red;
            unsigned short g1m1 = src[RIDX(ip, jm, dim)].green;
            unsigned short b1m1 = src[RIDX(ip, jm, dim)].blue;

            unsigned short r11 = src[RIDX(ip, jp, dim)].red;
            unsigned short g11 = src[RIDX(ip, jp, dim)].green;
            unsigned short b11 = src[RIDX(ip, jp, dim)].blue;

            pixel current_pixel = src[RIDX(i, j, dim)];

            current_pixel.red = (r00+r0m1+rm10+rm1m1+r01+rm11+r1m1+r10+r11)/9;
            current_pixel.green = (g00+g0m1+gm10+gm1m1+g01+gm11+g1m1+g10+g11)/9;
            current_pixel.blue = (b00+b0m1+bm10+bm1m1+b01+bm11+b1m1+b10+b11)/9;

            dst[RIDX(i, j, dim)] = current_pixel;
        }
    }   

    //bottom row
    for (j = 1; j < dim1; j++)
    {
        int jm = j-1;
        int jp = j+1;

        unsigned short r00 = src[RIDX(dim1, j, dim)].red;
        unsigned short g00 = src[RIDX(dim1, j, dim)].green;
        unsigned short b00 = src[RIDX(dim1, j, dim)].blue;

        unsigned short r0m1 = src[RIDX(dim1, jm, dim)].red;
        unsigned short g0m1 = src[RIDX(dim1, jm, dim)].green;
        unsigned short b0m1 = src[RIDX(dim1, jm, dim)].blue;

        unsigned short r01 = src[RIDX(dim1, jp, dim)].red;
        unsigned short g01 = src[RIDX(dim1, jp, dim)].green;
        unsigned short b01 = src[RIDX(dim1, jp, dim)].blue;

        unsigned short r11 = src[RIDX(dim2, j, dim)].red;
        unsigned short g11 = src[RIDX(dim2, j, dim)].green;
        unsigned short b11 = src[RIDX(dim2, j, dim)].blue;

        unsigned short r1m1 = src[RIDX(dim2, jm, dim)].red;
        unsigned short g1m1 = src[RIDX(dim2, jm, dim)].green;
        unsigned short b1m1 = src[RIDX(dim2, jm, dim)].blue;

        unsigned short r10 = src[RIDX(dim2, jp, dim)].red;
        unsigned short g10 = src[RIDX(dim2, jp, dim)].green;
        unsigned short b10 = src[RIDX(dim2, jp, dim)].blue;

        pixel current_pixel = src[RIDX(dim1, j, dim)];

        current_pixel.red = (r00+r0m1+r01+r11+r1m1+r10)/6;
        current_pixel.green = (g00+g0m1+g01+g11+g1m1+g10)/6;
        current_pixel.blue = (b00+b0m1+b01+b11+b1m1+b10)/6;

        dst[RIDX(dim1, j, dim)] = current_pixel;
    }

    //column 1
    for (i = 1; i < dim1; i++)
    {
        int im = i-1;
        int ip = i+1;

        unsigned short r00 = src[RIDX(i, 0, dim)].red;
        unsigned short g00 = src[RIDX(i, 0, dim)].green;
        unsigned short b00 = src[RIDX(i, 0, dim)].blue;

        unsigned short r0m1 = src[RIDX(im, 0, dim)].red;
        unsigned short g0m1 = src[RIDX(im, 0, dim)].green;
        unsigned short b0m1 = src[RIDX(im, 0, dim)].blue;

        unsigned short r01 = src[RIDX(ip, 0, dim)].red;
        unsigned short g01 = src[RIDX(ip, 0, dim)].green;
        unsigned short b01 = src[RIDX(ip, 0, dim)].blue;

        unsigned short r11 = src[RIDX(i, 1, dim)].red;
        unsigned short g11 = src[RIDX(i, 1, dim)].green;
        unsigned short b11 = src[RIDX(i, 1, dim)].blue;

        unsigned short r1m1 = src[RIDX(im, 1, dim)].red;
        unsigned short g1m1 = src[RIDX(im, 1, dim)].green;
        unsigned short b1m1 = src[RIDX(im, 1, dim)].blue;

        unsigned short r10 = src[RIDX(ip, 1, dim)].red;
        unsigned short g10 = src[RIDX(ip, 1, dim)].green;
        unsigned short b10 = src[RIDX(ip, 1, dim)].blue;

        pixel current_pixel = src[RIDX(i, 0, dim)];

        current_pixel.red = (r00+r0m1+r01+r11+r1m1+r10)/6;
        current_pixel.green = (g00+g0m1+g01+g11+g1m1+g10)/6;
        current_pixel.blue = (b00+b0m1+b01+b11+b1m1+b10)/6;

        dst[RIDX(i, 0, dim)] = current_pixel;
    }

    //column last
    for (i = 1; i < dim1; i++)
    {
        int im = i-1;
        int ip = i+1;

        unsigned short r00 = src[RIDX(i, dim1, dim)].red;
        unsigned short g00 = src[RIDX(i, dim1, dim)].green;
        unsigned short b00 = src[RIDX(i, dim1, dim)].blue;

        unsigned short r0m1 = src[RIDX(im, dim1, dim)].red;
        unsigned short g0m1 = src[RIDX(im, dim1, dim)].green;
        unsigned short b0m1 = src[RIDX(im, dim1, dim)].blue;

        unsigned short r01 = src[RIDX(ip, dim1, dim)].red;
        unsigned short g01 = src[RIDX(ip, dim1, dim)].green;
        unsigned short b01 = src[RIDX(ip, dim1, dim)].blue;

        unsigned short r11 = src[RIDX(i, dim2, dim)].red;
        unsigned short g11 = src[RIDX(i, dim2, dim)].green;
        unsigned short b11 = src[RIDX(i, dim2, dim)].blue;

        unsigned short r1m1 = src[RIDX(im, dim2, dim)].red;
        unsigned short g1m1 = src[RIDX(im, dim2, dim)].green;
        unsigned short b1m1 = src[RIDX(im, dim2, dim)].blue;

        unsigned short r10 = src[RIDX(ip, dim2, dim)].red;
        unsigned short g10 = src[RIDX(ip, dim2, dim)].green;
        unsigned short b10 = src[RIDX(ip, dim2, dim)].blue;

        pixel current_pixel = src[RIDX(i, dim1, dim)];

        current_pixel.red = (r00+r0m1+r01+r11+r1m1+r10)/6;
        current_pixel.green = (g00+g0m1+g01+g11+g1m1+g10)/6;
        current_pixel.blue = (b00+b0m1+b01+b11+b1m1+b10)/6;

        dst[RIDX(i, dim1, dim)] = current_pixel;
    }
}





/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

