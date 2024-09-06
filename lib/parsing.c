
#include <stdint.h>
#include <parsing.h>
#include <math.h>
// implement interpolation here
int interpolation(uint16_t channel) {
	// write interpolation code here

// Function to perform linear interpolation between two points
float interpolate(uint16_t y0, uint16_t y1, float x0, float x1, float x) {
    // Linear interpolation formula
    return y0 + ((x - x0) / (x1 - x0)) * (y1 - y0);
}

// Creating 11-bit channel from the buffer
uint16_t* parse_buffer(uint8_t buff[]) { 
    // to store channels
    static uint16_t channel[16];

    // Masking byte-shifting bits (value in hexadecimal '0x07FF' for 11 bits)
    uint16_t mask = 0x7FF;

    // Creating channels (same logic as you provided)
    channel[0]  = ((buff[1] | buff[2]<<8)                 & mask);
    channel[1]  = ((buff[2]>>3 | buff[3]<<5)              & mask);
    channel[2]  = ((buff[3]>>6 | buff[4]<<2 | buff[5]<<10) & mask);
    channel[3]  = ((buff[5]>>1 | buff[6]<<7)              & mask);
    channel[4]  = ((buff[6]>>4 | buff[7]<<4)              & mask);
    channel[5]  = ((buff[7]>>7 | buff[8]<<1 | buff[9]<<9)  & mask);
    channel[6]  = ((buff[9]>>2 | buff[10]<<6)             & mask);
    channel[7]  = ((buff[10]>>5| buff[11]<<3)             & mask);
    channel[8]  = ((buff[12]   | buff[13]<<8)             & mask);
    channel[9]  = ((buff[13]>>3| buff[14]<<5)             & mask);
    channel[10] = ((buff[14]>>6| buff[15]<<2| buff[16]<<10)& mask);
    channel[11] = ((buff[16]>>1| buff[17]<<7)             & mask);
    channel[12] = ((buff[17]>>4| buff[18]<<4)             & mask);
    channel[13] = ((buff[18]>>7| buff[19]<<1| buff[20]<<9) & mask);
    channel[14] = ((buff[20]>>2| buff[21]<<6)             & mask);
    channel[15] = ((buff[21]>>5| buff[22]<<3)             & mask);

    return channel;
}
// creating 11 bit channel
uint16_t *parse_buffer(uint8_t buff[]) { 
-
	// to store channels
	static uint16_t channel[16];

	// masking byte shiftings bits (value in hexa '0x07FF')
	uint16_t mask = 0x7ff;

	// creating channels 
        channel[0]  = ((buff[1] | buff[2]<<8)                 & mask);
        channel[1]  = ((buff[2]>>3 | buff[3]<<5)              & mask);
        channel[2]  = ((buff[3]>>6 | buff[4]<<2 | buff[5]<<10) & mask);
        channel[3]  = ((buff[5]>>1 | buff[6]<<7)              & mask);
        channel[4]  = ((buff[6]>>4 | buff[7]<<4)              & mask);
        channel[5]  = ((buff[7]>>7 | buff[8]<<1 | buff[9]<<9)  & mask);
        channel[6]  = ((buff[9]>>2 | buff[10]<<6)             & mask);
        channel[7]  = ((buff[10]>>5| buff[11]<<3)             & mask);
        channel[8]  = ((buff[12]   | buff[13]<<8)             & mask);
        channel[9]  = ((buff[13]>>3| buff[14]<<5)             & mask);
        channel[10] = ((buff[14]>>6| buff[15]<<2| buff[16]<<10)& mask);
        channel[11] = ((buff[16]>>1| buff[17]<<7)             & mask);
        channel[12] = ((buff[17]>>4| buff[18]<<4)             & mask);
        channel[13] = ((buff[18]>>7| buff[19]<<1| buff[20]<<9) & mask);
        channel[14] = ((buff[20]>>2| buff[21]<<6)             & mask);
        channel[15] = ((buff[21]>>5| buff[22]<<3)             & mask);

	return channel;

// Function to interpolate across channels (useful for your data processing)
void apply_interpolation(uint16_t *channels) {
    // Example: interpolate between channel 0 and 1 at midpoint
    float x0 = 0.0, x1 = 1.0;
    float midpoint = 0.5;

    // Linear interpolation between channels[0] and channels[1]
    float result = interpolate(channels[0], channels[1], x0, x1, midpoint);

    // Print or store the result as needed
    printf("Interpolated value between channel 0 and 1 at midpoint: %f\n", result);
}

int main() {
    // Example buffer (you can replace this with actual data)
    uint8_t buffer[23] = {0, 255, 7, 255, 31, 255, 63, 255, 127, 255, 255, 1, 3, 7, 15, 31, 63, 127, 255, 7, 15, 31, 63};

    // Parse the buffer into 11-bit channels
    uint16_t* channels = parse_buffer(buffer);

    // Apply interpolation
    apply_interpolation(channels);

    return 0;
}
