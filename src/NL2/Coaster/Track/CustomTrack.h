#ifndef LIB_NL2PARK_CUSTOM_TRACK_H
#define LIB_NL2PARK_CUSTOM_TRACK_H

#include <vector>

#include "../../../Stream/Chunk.h"
#include "Track.h"
#include "RollPoint.h"
#include "Vertex.h"
#include "Trigger.h"
#include "Parameter4D.h"
#include "Segment.h"
#include "Separator.h"
#include "Section/Section.h"
#include "../Support/RailNode.h"

namespace NoLimits {
    namespace NoLimits2 {
        class CustomTrack: public Stream::Chunk, public Track  {
        public:
            CustomTrack();

            void debug() {
                getSegment()->debug();
                getSection()->debug();
            }

            void read(File::File *file);
            void write(File::File *file);

            RollPoint *getFirstRollPoint() const;
            RollPoint *getLastRollPoint() const;

            std::vector<Vertex*> getVertex() const;
            void insertVertex(Vertex *value);

            std::vector<RollPoint*> getRollPoint() const;
            void insertRollPoint(RollPoint* value);

            std::vector<Trigger*> getTrigger() const;
            void insertTrigger(Trigger* value);

            std::vector<RailNode*> getRailNode() const;
            void insertRailNode(RailNode* value);

            std::vector<Parameter4D*> getParameter4D() const;
            void insertParameter4D(Parameter4D* value);

            std::vector<Separator*> getSeparator() const;
            void insertSeparator(Separator* value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            Section *getSection() const;
            void setSection(Section *value);

            bool getClosed() const;
            void setClosed(bool value);

            virtual Section *getSectionByName(std::string);

            std::string getChunkName() { return "CUTK"; }

        private:
            std::vector<Vertex*> vertex;
            std::vector<RollPoint*> rollPoint;
            std::vector<Trigger*> trigger;
            std::vector<RailNode*> railNode;
            std::vector<Parameter4D*> parameter4D;
            std::vector<Separator*> separator;

            RollPoint *firstRollPoint;
            RollPoint *lastRollPoint;

            Segment *segment;
            Section *section;

            bool closed;
        };
    }
}

#endif // LIB_NL2PARK_CUSTOM_TRACK_H
