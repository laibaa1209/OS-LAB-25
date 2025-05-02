## Code workout 1:
### part a:
![image](https://github.com/user-attachments/assets/70922b4b-1c8a-41c9-a252-fd9f5263c54f)

### part b
b) What functionality is implemented by full and empty semaphores?

    empty:

        Initialized to BUFFER_SIZE.

        Tracks how many empty slots are available in the buffer.

        The producer will wait (sem_wait(&empty)) if no space is available.

    full:

        Initialized to 0.

        Tracks how many full slots (i.e., produced items) exist in the buffer.

        The consumer will wait (sem_wait(&full)) if there is nothing to consume.

Together, these semaphores synchronize access to the bounded buffer, ensuring the producer doesn’t overflow it and the consumer doesn’t read from an empty slot.

### part c:
c) What purpose does the sleep() function serve in producer and consumer functions?

    sleep(rand() % 3) introduces a random delay (0 to 2 seconds).

    This simulates real-world processing time:

        Producer simulates item creation time.

        Consumer simulates item consumption/processing time.

    It also makes thread switching more visible and the output easier to observe/debug by reducing the speed of execution.

## Code Workout 2:
### part a:
![image](https://github.com/user-attachments/assets/2b41ea81-c6bb-47da-8973-8a444b7a7f12)

part b:
![image](https://github.com/user-attachments/assets/26b8d537-58fa-4b68-9082-ac68e4d1575c)


    
