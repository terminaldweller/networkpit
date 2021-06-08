FROM frrouting/frr:v7.5.1
COPY ./docker-entry.sh /scripts/docker-entry.sh
RUN chmod +x /scripts/docker-entry.sh
ENTRYPOINT ["/scripts/docker-entry.sh"]
