# Arduino Avail

Method for comparing two milliseconds to each other for asserting `true`/`false` criteria.

## Example:

```c++
unsigned long lastTimestamp = 123455; // in milliseconds
unsigned long margin = 150; // milliseconds before needing to do something

if (avail(&margin, &lastTimestamp)) {
    // do stuff after waiting the length of 'margin'
} else {
    // continue looping through code
}
```

If you need to know whether or not a rollover has occurred with the millis() counter, do the following:

```c++
unsigned long lastTimestamp = 123455; // in milliseconds
unsigned long margin = 150; // milliseconds before needing to do something
bool rollover; // this will be assigned the approrpiate flag when being passed by reference

if (avail(&margin, &lastTimestamp, rollover)) {
    // do stuff after waiting the length of 'margin'
} else {
    // continue looping through code
}

if (rollover) {
    // perform other necessary logic
}
```