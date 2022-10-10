/*
Melissa Gray
10/6/2022

Header file for Color class
*/

#ifndef COLOR_H
#define COLOR_H


class Color{
    private:
        // RGBA values in an array
        int rgba[4]{};

    public:
        // Predefined colors
        static const int red[4];
        static const int green[4];
        static const int blue[4];
        static const int black[4];
        static const int goldenrod[4];
        static const int turquoise[4];
        static const int seaGreen[4];
        static const int gray[4];
        static const int white[4];

        // Getters
        int getRed() { return rgba[0]; }
        int getGreen() { return rgba[1]; }
        int getBlue() { return rgba[2]; }
        int getAlpha() { return rgba[3]; }

        // Setters
        int setRed(int r) { rgba[0] = r; }
        int setGreen(int g) { rgba[1] = g; }
        int setBlue(int b) { rgba[2] = b; }
        int setAlpha(int a) { rgba[3] = a; }

        // Color manipulation of this Color instance
        void invert();
        Color complement(Color other);

        // Color manipulation of multiple Color instances
        static Color add(Color others[]);
        static Color subtract(Color others[]);
        static Color multiply(Color others[]);
        static Color divide(Color others[]);
};

#endif
