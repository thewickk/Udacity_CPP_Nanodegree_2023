#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization(); 


  // Member variables to hold previous cpu information for calculating current CPU usage
 private:
    unsigned long prevuser_{};
    unsigned long prevnice_{};
    unsigned long prevsystem_{};
    unsigned long previdle_{};
    unsigned long previowait_{};
    unsigned long previrq_{};
    unsigned long prevsoftirq_{};
    unsigned long prevsteal_{};
    unsigned long prevguest_{};
    unsigned long prevguest_nice_{};
};

#endif