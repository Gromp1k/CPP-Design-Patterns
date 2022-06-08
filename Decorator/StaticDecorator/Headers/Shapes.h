#include <string>
#include <sstream>
    class IShape{ 
        public:
            virtual operator std::string()=0; 
    };

    class Circle : public IShape {
        private:
            float _radius;
        public:
            Circle(const float& = 0);
            void resize(float);
            operator std::string() override;
    }; 

    class Square : public IShape {
        private:
            float _side;
        public:
            Square(const float& = 0);
            operator std::string() override;
    }; 

    template <class T>
    class ColoredShape : public T {
        private:
            std::string _color;
        public:
            static_assert(std::is_base_of<IShape,T>::value, "Invalid template argument");

            template <typename... Args>
            ColoredShape(const std::string&, Args&&...);
            operator std::string() override;
    };
    
    template <class T>
    class TransparentShape : public T {
        private:
            uint8_t _alpha;
        public:
            template <typename... Args>
            TransparentShape(const uint8_t&, Args&&...);
            operator std::string() override;
    };


template<class T>
template<typename... Args>
ColoredShape<T>::ColoredShape(const std::string& color, Args&&... args) : _color(color), T(std::forward<Args>(args)...){}

template<class T>
ColoredShape<T>::operator std::string() {
    std::ostringstream oss;
    oss << T::operator std::string() << " has the color " << _color;
    return oss.str();
}

template<class T>
template<typename... Args>
TransparentShape<T>::TransparentShape(const uint8_t& alpha, Args&&... args) : _alpha(alpha), T(std::forward<Args>(args)...){}

template<class T>
TransparentShape<T>::operator std::string(){
    std::ostringstream oss;
    oss << T::operator std::string() << " has " << static_cast<float>(_alpha) / 255.f * 100.f << " % transparency";
    return oss.str();
}