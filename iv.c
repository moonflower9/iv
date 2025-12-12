#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

// skip comment function
void skip_comments(FILE *fp)
{
    int c;
    while ((c = fgetc(fp)) == '#') {
        while ((c = fgetc(fp)) != '\n' && c != EOF);
    }
    ungetc(c, fp);
}

int main(int argc, char **argv)
{
    // exit if incorrect args are provided
    if (argc != 2) {
        fprintf(stderr, "usage: %s <path-to-image>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    // check if null
    if (!in) {
        perror("fopen");
        return 1;
    }
    
    // read header
    char magic[16];
    fgets(magic, sizeof(magic), in);
    int width, height, maxval;
    skip_comments(in);
    fscanf(in, "%d %d", &width, &height);
    skip_comments(in);
    fscanf(in, "%d", &maxval);
    fgetc(in); // consume whitespace
    
    // allocate memory for pixel data
    int numPixels = width * height;
    unsigned char *pixels = malloc(numPixels * 3);

    // read binary from file
    fread(pixels, 3, numPixels, in);
    fclose(in);

    // display window and image
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow); 

    Uint32 *dst = psurface->pixels;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Uint8 r = pixels[(y * width + x) * 3];
            Uint8 g = pixels[(y * width + x) * 3 + 1];
            Uint8 b = pixels[(y * width + x) * 3 + 2];
            dst[y * width + x] = SDL_MapRGB(psurface->format, r, g, b);
        }
    }

    SDL_UpdateWindowSurface(pwindow);

    SDL_Delay(3000);
    
    free(pixels);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
}
