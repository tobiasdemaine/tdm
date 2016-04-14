#ifndef fft_hh
#define fft_hh


// (complex) fast fourier transformation

/* The input in data[0..2N-1] is replaced by its fft or inverse fft, depending
only on isign (+1 for fft, -1 for inverse fft). The number of complex numbers
N must be a power of 2 (which is not checked). The function fft() differs
mainly in the option base and the normalisation from the function four1() in
Numerical Recipes in C, Page 507. The storage arrangement is explained
there. */

void
fft( float data[], int N, int isign );


// (real) fast fourier transformation

/* The input in data[0..N-1] is replaced by its fft or inverse fft, depending
only on isign (+1 for fft, -1 for inverse fft). The number of real numbers N
must be a power of 2 (which is not checked). The function rfft() differs
mainly in the option base and the normalisation from the function realft() in
Numerical Recipes in C, Page 516. The storage arrangement is explained
there. */

void
rfft( float data[], int N, int isign );


#endif
