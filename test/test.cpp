#include <iostream>
#include <libnolimits.h>

using namespace NoLimits::NoLimits2;

int main() {
    Park *customPark = new Park();
    customPark->insertCoaster(new Coaster("TestCoaster"));

    Coaster *coaster = customPark->getCoaster("TestCoaster");

    CustomTrack *track1 = new CustomTrack();
    CustomTrack *track2 = new CustomTrack();

    Vertex *vertex1 = new Vertex();
    vertex1->setPosition(glm::vec4(0.0f, 11.0f, 1.0f, 1.0f));

    Vertex *vertex2 = new Vertex();
    vertex2->setPosition(glm::vec4(0.0f, 6.0f, 6.0f, 1.0f));

    Vertex *vertex3 = new Vertex();
    vertex3->setPosition(glm::vec4(0.0f, 12.0f, 2.0f, 1.0f));

    Vertex *vertex4 = new Vertex();
    vertex4->setPosition(glm::vec4(0.0f, 7.0f, 7.0f, 1.0f));

    track1->insertVertex(vertex1);
    track1->insertVertex(vertex2);

    track2->insertVertex(vertex3);
    track2->insertVertex(vertex4);

    coaster->insertTrack(track1);
    coaster->insertTrack(track2);

    FreeNode *f1 = new FreeNode();
    FreeNode *f2 = new FreeNode();
    FreeNode *f3 = new FreeNode();

    f1->setPosition(glm::vec3(0.0f, 10.0f, 0.0f));
    f2->setPosition(glm::vec3(5.0f, 5.0f, 5.0f));
    f3->setPosition(glm::vec3(-5.0f, 5.0f, -5.0f));

    uint32_t freeNode1Index = coaster->getSupport()->insertFreeNode(f1);
    uint32_t freeNode2Index = coaster->getSupport()->insertFreeNode(f2);
    uint32_t freeNode3Index = coaster->getSupport()->insertFreeNode(f3);

    Beam *beam1 = new Beam();
    beam1->getConnection1()->setType(BeamConnection::Type::FreeNode);
    beam1->getConnection1()->setIndex1(freeNode1Index);

    beam1->getConnection2()->setType(BeamConnection::Type::FreeNode);
    beam1->getConnection2()->setIndex1(freeNode2Index);

    uint32_t beam1Index1 = coaster->getSupport()->insertBeam(beam1);

    Flange *flange1 = new Flange();
    flange1->setPosition(0.5f);

    BeamNode *beamNode1 = new BeamNode();
    beamNode1->setPosition(0.25f);

    BeamNode *beamNode2 = new BeamNode();
    beamNode2->setPosition(0.375f);

    BeamNode *beamNode3 = new BeamNode();
    beamNode3->setPosition(0.625f);

    uint32_t beamNode1Index = beam1->insertBeamNode(beamNode1);
    uint32_t beamNode2Index = beam1->insertBeamNode(beamNode2);
    uint32_t beamNode3Index = beam1->insertBeamNode(beamNode3);
    beam1->insertFlange(flange1);

    Beam *beam2 = new Beam();

    beam2->getConnection1()->setType(BeamConnection::Type::FreeNode);
    beam2->getConnection1()->setIndex1(freeNode3Index);

    beam2->getConnection2()->setType(BeamConnection::Type::BeamNode);
    beam2->getConnection2()->setIndex1(beam1Index1);
    beam2->getConnection2()->setIndex2(beamNode1Index);

    coaster->getSupport()->insertBeam(beam2);

    RailConnector *railConnector = new RailConnector();
    railConnector->setPosition(0.375f);

    RailConnector *railConnector2 = new RailConnector();
    railConnector2->setPosition(0.625f);

    RailConnector *railConnector3 = new RailConnector();
    railConnector3->setPosition(0.625f);

    track1->insertRailConnector(railConnector);
    track1->insertRailConnector(railConnector2);

    track2->insertRailConnector(railConnector3);

    Beam *beam3 = new Beam();

    beam3->getConnection1()->setType(BeamConnection::Type::BeamNode);
    beam3->getConnection1()->setIndex1(beam1Index1);
    beam3->getConnection1()->setIndex2(beamNode2Index);

    beam3->getConnection2()->setType(BeamConnection::Type::RailConnector);
    beam3->getConnection2()->setIndex1(0);
    beam3->getConnection2()->setIndex2(0);
    beam3->getConnection2()->setIndex3(0);

    Beam *beam4 = new Beam();

    beam4->getConnection1()->setType(BeamConnection::Type::BeamNode);
    beam4->getConnection1()->setIndex1(beam1Index1);
    beam4->getConnection1()->setIndex2(beamNode3Index);

    beam4->getConnection2()->setType(BeamConnection::Type::RailConnector);
    beam4->getConnection2()->setIndex1(1);
    beam4->getConnection2()->setIndex2(0);
    beam4->getConnection2()->setIndex3(0);

    coaster->getSupport()->insertBeam(beam3);
    coaster->getSupport()->insertBeam(beam4);

    customPark->save("test/TestPark/CustomPark.nl2park");
    return 0;
}
