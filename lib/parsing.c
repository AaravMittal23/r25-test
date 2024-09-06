#include <stdint.h>
#include <parsing.h>
#include <math.h>
// implement interpolation here
int interpolation(uint16_t channel) {
	// write interpolation code here
	 // Define start and end points for interpolation
    int n = 0; // Index of the first channel value
    int m = 1; // Index of the second channel value

    // x0, y0 are for the first point (channel[n]), x1, y1 for the second point (channel[m])
    float x0 = n, x1 = m;
    uint16_t y0 = channel[n];
    uint16_t y1 = channel[m];

    // Let's interpolate for some intermediate x value, say x = 0.5 (midpoint)
    float x = 0.5;

    // Linear interpolation formula
    float interpolated_value = y0 + ((x - x0) / (x1 - x0)) * (y1 - y0);

    // Cast back to integer
    return (int)round(interpolated_value);
}


