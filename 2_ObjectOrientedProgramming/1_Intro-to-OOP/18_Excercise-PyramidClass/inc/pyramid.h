#ifndef PYRAMID_H
#define PYRAMID_H

class Pyramid
{
    public:
        Pyramid(int length, int width, int height);
        
        // Accessors
        int GetLength() const;
        int GetWidth() const;
        int GetHeight() const;

        // Mutators
        void SetLength(int length);
        void SetWidth(int width);
        void SetHeight(int height);

        // Member functions
        float Volume() const;

    private:
        int length_;
        int width_;
        int height_;
        void Validate();
};


#endif // PYRAMID_H