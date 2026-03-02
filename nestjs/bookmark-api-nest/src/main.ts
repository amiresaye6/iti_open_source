import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { ValidationPipe } from '@nestjs/common';
import morgan from 'morgan';
import dotenv from 'dotenv';

dotenv.config();
async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  app.useGlobalPipes(new ValidationPipe());
  // eslint-disable-next-line @typescript-eslint/no-unsafe-call
  app.use(morgan('dev'));

  await app.listen(process.env.PORT ?? 1234);
}
bootstrap().catch((err) => {
  console.error(err);
  process.exit(1);
});
