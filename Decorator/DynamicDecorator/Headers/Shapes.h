#ifndef _SHAPES_H_
#define _SHAPES_H_

#include <string>
    class IShape{ 
        public:
            virtual operator std::string()=0; 
    };

    class Circle : public IShape {
        private:
            float _radius;
        public:
            Circle(const float& = 0);
            void resize(const float&);
            operator std::string() override;
    }; 

    class Square : public IShape {
        private:
            float _side;
        public:
            Square(const float& = 0);
            operator std::string() override;
    }; 

    class ColoredShape : public IShape {
        private:
            const IShape& _shape;
            std::string _color;
        public:
            ColoredShape(const IShape&, const std::string& );
            operator std::string() override;
    };

    class TransparentShape : public IShape {
        private:
            const IShape& _shape;
            uint8_t _alpha;
        public:
            TransparentShape(const IShape&, const uint8_t&);
            operator std::string() override;
    };

#endif