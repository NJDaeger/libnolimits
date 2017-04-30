#ifndef LIB_NL2PARK_SKY_H
#define LIB_NL2PARK_SKY_H

#include <Stream/Chunk.h>
#include <nolimits.h>

namespace Library {
    namespace NL2Park {
        class Sky: public Stream::Chunk {
        public:
            Sky() {
                setCurrentDate(glm::vec2(7, 17));
                setCurrentTime(glm::vec2(9, 30));
                setOverrideDefaultDateTime(false);
            }

            void debug() {
                std::cout << "Sky[setCurrentDate]: " << Helper::debug(getCurrentDate()) << std::endl;
                std::cout << "Sky[getCurrentTime]: " << Helper::debug(getCurrentTime()) << std::endl;
                std::cout << "Sky[getOverrideDefaultDateTime]: " << getOverrideDefaultDateTime() << std::endl;
            }

            void read(File::File *file);
            void write(File::File *file);

            bool getOverrideDefaultDateTime() const;
            void setOverrideDefaultDateTime(bool value);

            glm::vec2 getCurrentDate() const;
            void setCurrentDate(const glm::vec2 &value);

            glm::vec2 getCurrentTime() const;
            void setCurrentTime(const glm::vec2 &value);

        private:
            bool overrideDefaultDateTime;
            glm::vec2 currentDate;
            glm::vec2 currentTime;
        };
    }
}

#endif // SKY_H
