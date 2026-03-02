import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getInfo(): object {
    return {
      message: 'info about this api :__:',
      requists: [
        'get all bookmarks',
        'get bookmark by id',
        'create a bookmark',
        'update a bookmark',
        'delete a bookmark',
      ],
      version: '1.0.0',
    };
  }
}
