#ifndef LIB_NL2PARK_FRICTION_H
#define LIB_NL2PARK_FRICTION_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class CustomFriction: public Stream::Chunk {
        public:
            CustomFriction() {}

            void debug() {
                std::cout << "CustomFriction[getConstFrictionParameter]: " << getConstFrictionParameter() << std::endl;
                std::cout << "CustomFriction[getAirResistanceParameter]: " << getAirResistanceParameter() << std::endl;
            }

            void write(File::File *file);
            void read(File::File *file);

            double getConstFrictionParameter() const;
            void setConstFrictionParameter(double value);

            double getAirResistanceParameter() const;
            void setAirResistanceParameter(double value);

        private:
            double constFrictionParameter;
            double airResistanceParameter;

        protected:
            std::string getChunkName() { return "CUFR"; }
        };
    }
}

#endif // LIB_NL2PARK_FRICTION_H