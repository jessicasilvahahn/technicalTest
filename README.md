
# TechnicalTest 

## Environment

### Libraries

1. `g++/gcc 11`
2. `cmake 3.22.1`
3. `boost 1.74.0`
4. `docker 24.0.5`

### Running the Tests

#### GitHub CI/CD

To execute the tasks using GitHub Actions (CI/CD):
1. Navigate to `Actions > All workflows > Run Tests > Run workflow > Branch main > Run workflow`.
2. Wait for the pipeline to execute, and then click on the last execution.
3. Expand the steps `Run Tests` to view the results.

#### Local

For see output in a local directory build the container by Dockerfile:
1. Change the .env file TEST_TO_RUN=clientTest.sh
2. docker build -t ubuntu-boost env/
3. Change  `/mnt/c/Users/Jessica/Documents/studies/git/`  for your local path and execute
```sh
docker run \
            --privileged \
            --env-file /mnt/c/Users/Jessica/Documents/studies/git/technicalTest/env/.env \
            -v /mnt/c/Users/Jessica/Documents/studies/git/technicalTest:/data/technicalTest:rw \
            ubuntu-boost

```
4. See the recovery file in the output and the split files in the data
5. Compare `output/output.pdf` file with sample file `resume.pdf`